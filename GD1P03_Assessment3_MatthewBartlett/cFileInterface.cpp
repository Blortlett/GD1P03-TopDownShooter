/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cFileInterface]
Description : [This class loads and saves levels for use in the level editor and when playing each level]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#include "cFileInterface.h"
// Extra includes for level stuff
#include "cEnemySpawner.h"

cFileInterface::cFileInterface(cBaseLevel* _CurrentLevel)
{
    // Initialize COM at startup to avoid initializing/uninitializing for each dialog
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cerr << "Failed to initialize COM during object creation. HRESULT: 0x"
            << std::hex << hr << std::dec << std::endl;
        // We won't throw here, but file dialogs might not work
    }

    // Set current level
    mCurrentLevel = _CurrentLevel;
    // Check Current Level
    if (!mCurrentLevel) {
        std::cerr << "Error: mCurrentLevel is null" << std::endl;
        return;
    }
}

cFileInterface::~cFileInterface()
{
    // Clean up COM on destruction
    CoUninitialize();
}

void cFileInterface::SaveLevelDialog() {
    std::wstring filePath;
    if (!ShowFileSaveDialog(filePath, L"JSON files", L"*.json")) {
        return;
    }

    SaveLevelToFile(filePath);
}

void cFileInterface::LoadLevelDialog() {
    std::wstring filePath;
    if (!ShowFileOpenDialog(filePath, L"JSON files", L"*.json")) {
        return;
    }

    LoadLevelFromFile(filePath);
}

void cFileInterface::LoadLevelByName(const std::string& levelName) {
    // Construct file path (e.g., "Levels/levelName.json")
    std::filesystem::path filePath = "Assets/Levels/" + levelName + ".json";
    LoadLevelFromFile(filePath.wstring());
}

bool cFileInterface::ShowFileSaveDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt) {
    // COM should already be initialized in constructor, no need to initialize again

    bool result = false;
    // Create Save File Dialog
    IFileSaveDialog* pFileSave = nullptr;
    HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
        IID_IFileSaveDialog, (void**)&pFileSave);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { fileTypeDesc, fileTypeExt },
            { L"All files", L"*.*" }
        };
        pFileSave->SetFileTypes(2, fileTypes);
        pFileSave->SetDefaultExtension(L"json");

        // Show dialog
        hr = pFileSave->Show(NULL);
        if (SUCCEEDED(hr)) {
            IShellItem* pItem;
            hr = pFileSave->GetResult(&pItem);
            if (SUCCEEDED(hr)) {
                PWSTR pszFilePath;
                hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                if (SUCCEEDED(hr)) {
                    outFilePath = pszFilePath;
                    result = true;
                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileSave->Release();
    }
    else {
        std::cerr << "Failed to create FileSaveDialog. HRESULT: 0x"
            << std::hex << hr << std::dec << std::endl;
    }

    return result;
}

bool cFileInterface::ShowFileOpenDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt) {
    // COM should already be initialized in constructor, no need to initialize again

    bool result = false;
    // Create Open File Dialog
    IFileOpenDialog* pFileOpen = nullptr;
    HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
        IID_IFileOpenDialog, (void**)&pFileOpen);

    if (SUCCEEDED(hr)) {
        // Set file types
        COMDLG_FILTERSPEC fileTypes[] = {
            { fileTypeDesc, fileTypeExt },
            { L"All files", L"*.*" }
        };
        pFileOpen->SetFileTypes(2, fileTypes);
        pFileOpen->SetDefaultExtension(L"json");

        // Show dialog
        hr = pFileOpen->Show(NULL);
        if (SUCCEEDED(hr)) {
            IShellItem* pItem;
            hr = pFileOpen->GetResult(&pItem);
            if (SUCCEEDED(hr)) {
                PWSTR pszFilePath;
                hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
                if (SUCCEEDED(hr)) {
                    outFilePath = pszFilePath;
                    result = true;
                    CoTaskMemFree(pszFilePath);
                }
                pItem->Release();
            }
        }
        pFileOpen->Release();
    }
    else {
        std::cerr << "Failed to create FileOpenDialog. HRESULT: 0x"
            << std::hex << hr << std::dec << std::endl;
    }

    return result;
}

void cFileInterface::SaveLevelToFile(const std::wstring& filePath) {
    // Create JSON document
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    // Save all platforms
    SaveFullWallCollidersToJson(doc, allocator);
    SaveHalfWallCollidersToJson(doc, allocator);
    SaveEnemySpawnersToJson(doc, allocator);

    // Save player spawn
    //SavePlayerSpawnToJson(doc, allocator);

    // Write to JSON string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    // Write to file
    std::ofstream outFile(filePath);
    if (outFile.is_open()) {
        outFile << buffer.GetString();
        outFile.close();
        std::cout << "Level saved successfully to " << std::string(filePath.begin(), filePath.end()) << std::endl;
    }
    else {
        std::cerr << "Failed to open file for writing: " << std::string(filePath.begin(), filePath.end()) << std::endl;
    }
}

void cFileInterface::LoadLevelFromFile(const std::wstring& filePath) {
    // Read JSON file
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file: " << std::string(filePath.begin(), filePath.end()) << std::endl;
        return;
    }

    // Read file content into string
    std::string jsonContent((std::istreambuf_iterator<char>(inFile)),
        std::istreambuf_iterator<char>());
    inFile.close();

    // Parse JSON
    rapidjson::Document doc;
    if (doc.Parse(jsonContent.c_str()).HasParseError() || !doc.IsObject()) {
        std::cerr << "Failed to parse JSON file: " << std::string(filePath.begin(), filePath.end()) << std::endl;
        return;
    }

    // Clear existing objects

    // Load all platforms
    LoadFullWallColidersFromJson(doc);
    LoadHalfWallColidersFromJson(doc);
    LoadEnemySpawnersFromJson(doc);

    // Load player spawn
    //LoadPlayerSpawnFromJson(doc);

    std::cout << "Level loaded successfully from " << std::string(filePath.begin(), filePath.end()) << std::endl;
}

// Save Item Functions

// Multi item saving function // Save lists
void cFileInterface::SaveFullWallCollidersToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    // Create wall array
    rapidjson::Value ColliderArray(rapidjson::kArrayType);

    // Add each wall to json list
    for (auto* collider : mCurrentLevel->GetFullWallColliderList()) {
        if (!collider) {
            std::cerr << "Error: Null collider in FullWallColliders" << std::endl;
            continue;
        }

        rapidjson::Value fullWallColliderObj(rapidjson::kObjectType);
        sf::FloatRect bounds = collider->GetBounds();

        fullWallColliderObj.AddMember("x", bounds.position.x, allocator);
        fullWallColliderObj.AddMember("y", bounds.position.y, allocator);
        fullWallColliderObj.AddMember("width", bounds.size.x, allocator);
        fullWallColliderObj.AddMember("height", bounds.size.y, allocator);

        ColliderArray.PushBack(fullWallColliderObj, allocator);
    }

    doc.AddMember("FullWallColliders", ColliderArray, allocator);
}

void cFileInterface::SaveHalfWallCollidersToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
{
    // Create wall array
    rapidjson::Value ColliderArray(rapidjson::kArrayType);

    // Add each wall to json list
    for (auto* collider : mCurrentLevel->GetHalfWallColliderList()) {
        if (!collider) {
            std::cerr << "Error: Null collider in HalfWallColliders" << std::endl;
            continue;
        }

        rapidjson::Value halfWallColliderObj(rapidjson::kObjectType);
        sf::FloatRect bounds = collider->GetBounds();

        halfWallColliderObj.AddMember("x", bounds.position.x, allocator);
        halfWallColliderObj.AddMember("y", bounds.position.y, allocator);
        halfWallColliderObj.AddMember("width", bounds.size.x, allocator);
        halfWallColliderObj.AddMember("height", bounds.size.y, allocator);

        ColliderArray.PushBack(halfWallColliderObj, allocator);
    }

    doc.AddMember("HalfWallColliders", ColliderArray, allocator);
}

void cFileInterface::SaveEnemySpawnersToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator)
{
    // Create wall array
    rapidjson::Value spawnerArray(rapidjson::kArrayType);

    // Add each wall to json list
    for (auto* collider : mCurrentLevel->GetEnemySpawnerList()) {
        if (!collider) {
            std::cerr << "Error: Null EnemySpawner in EnemySpawnerList" << std::endl;
            continue;
        }

        rapidjson::Value enemySpawnerObj(rapidjson::kObjectType);
        sf::Vector2f position = collider->GetPosition();

        enemySpawnerObj.AddMember("x", position.x, allocator);
        enemySpawnerObj.AddMember("y", position.y, allocator);

        spawnerArray.PushBack(enemySpawnerObj, allocator);
    }

    doc.AddMember("EnemySpawnerList", spawnerArray, allocator);
}

/*      // Single item saving function
void cFileInterface::SavePlayerSpawnToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator) {
    if (mLevelPlatformList.mPlayerSpawn) {
        rapidjson::Value spawnObj(rapidjson::kObjectType);
        sf::Vector2f position = mLevelPlatformList.mPlayerSpawn->GetPosition();

        spawnObj.AddMember("x", position.x, allocator);
        spawnObj.AddMember("y", position.y, allocator);

        doc.AddMember("playerSpawn", spawnObj, allocator);
    }
}
*/

// Load Item Functions

void cFileInterface::LoadFullWallColidersFromJson(const rapidjson::Document& doc) {
    // Check for platforms array
    if (!doc.HasMember("FullWallColliders") || !doc["FullWallColliders"].IsArray()) {
        std::cerr << "No valid FullWall array in JSON" << std::endl;
        return;
    }

    const rapidjson::Value& ColliderArray = doc["FullWallColliders"];
    for (rapidjson::SizeType i = 0; i < ColliderArray.Size(); ++i) {
        const rapidjson::Value& fullWallColliderObj = ColliderArray[i];
        if (fullWallColliderObj.IsObject() &&
            fullWallColliderObj.HasMember("x") && fullWallColliderObj["x"].IsFloat() &&
            fullWallColliderObj.HasMember("y") && fullWallColliderObj["y"].IsFloat() &&
            fullWallColliderObj.HasMember("width") && fullWallColliderObj["width"].IsFloat() &&
            fullWallColliderObj.HasMember("height") && fullWallColliderObj["height"].IsFloat()) {
            // Extract platform data
            float x = fullWallColliderObj["x"].GetFloat();
            float y = fullWallColliderObj["y"].GetFloat();
            float width = fullWallColliderObj["width"].GetFloat();
            float height = fullWallColliderObj["height"].GetFloat();

            // Create new platform
            sf::Vector2f position(x, y);
            sf::Vector2f size(width, height);
            sf::FloatRect bounds(position, size);
            cFullWall* fullWall = new cFullWall(bounds);
            mCurrentLevel->AddFullWallToList(fullWall);
        }
        else {
            std::cerr << "Invalid platform object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << ColliderArray.Size() << " FullWalls" << std::endl;
}

void cFileInterface::LoadHalfWallColidersFromJson(const rapidjson::Document& doc)
{
    // Check for platforms array
    if (!doc.HasMember("HalfWallColliders") || !doc["HalfWallColliders"].IsArray()) {
        std::cerr << "No valid HalfWall array in JSON" << std::endl;
        return;
    }

    const rapidjson::Value& ColliderArray = doc["HalfWallColliders"];
    for (rapidjson::SizeType i = 0; i < ColliderArray.Size(); ++i) {
        const rapidjson::Value& halfWallColliderObj = ColliderArray[i];
        if (halfWallColliderObj.IsObject() &&
            halfWallColliderObj.HasMember("x") && halfWallColliderObj["x"].IsFloat() &&
            halfWallColliderObj.HasMember("y") && halfWallColliderObj["y"].IsFloat() &&
            halfWallColliderObj.HasMember("width") && halfWallColliderObj["width"].IsFloat() &&
            halfWallColliderObj.HasMember("height") && halfWallColliderObj["height"].IsFloat()) {
            // Extract platform data
            float x = halfWallColliderObj["x"].GetFloat();
            float y = halfWallColliderObj["y"].GetFloat();
            float width = halfWallColliderObj["width"].GetFloat();
            float height = halfWallColliderObj["height"].GetFloat();

            // Create new platform
            sf::Vector2f position(x, y);
            sf::Vector2f size(width, height);
            sf::FloatRect bounds(position, size);
            cHalfWall* halfWall = new cHalfWall(bounds);
            mCurrentLevel->AddHalfWallToList(halfWall);
        }
        else {
            std::cerr << "Invalid platform object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << ColliderArray.Size() << " HalfWalls" << std::endl;
}

void cFileInterface::LoadEnemySpawnersFromJson(const rapidjson::Document& doc)
{
    // Check for platforms array
    if (!doc.HasMember("EnemySpawnerList") || !doc["EnemySpawnerList"].IsArray()) {
        std::cerr << "No valid EnemySpawnerList array in JSON" << std::endl;
        return;
    }

    const rapidjson::Value& SpawnerArray = doc["EnemySpawnerList"];
    for (rapidjson::SizeType i = 0; i < SpawnerArray.Size(); ++i) {
        const rapidjson::Value& enemySpawnerListObj = SpawnerArray[i];
        if (enemySpawnerListObj.IsObject() &&
            enemySpawnerListObj.HasMember("x") && enemySpawnerListObj["x"].IsFloat() &&
            enemySpawnerListObj.HasMember("y") && enemySpawnerListObj["y"].IsFloat()) 
        {
            // Extract platform data
            float x = enemySpawnerListObj["x"].GetFloat();
            float y = enemySpawnerListObj["y"].GetFloat();

            // Create new platform
            sf::Vector2f position(x, y);
            cEnemySpawner* enemySpawner = new cEnemySpawner(position);
            mCurrentLevel->AddEnemySpawnerToList(enemySpawner);
        }
        else {
            std::cerr << "Invalid spawener object at index " << i << std::endl;
        }
    }

    std::cout << "Loaded " << SpawnerArray.Size() << " EnemySpawners" << std::endl;
}

/*
void cFileInterface::LoadPlayerSpawnFromJson(const rapidjson::Document& doc) {
    if (doc.HasMember("playerSpawn") && doc["playerSpawn"].IsObject()) {
        const rapidjson::Value& spawnObj = doc["playerSpawn"];
        if (spawnObj.HasMember("x") && spawnObj["x"].IsFloat() &&
            spawnObj.HasMember("y") && spawnObj["y"].IsFloat()) {

            float x = spawnObj["x"].GetFloat();
            float y = spawnObj["y"].GetFloat();

            cPlatformLevelStart* playerSpawn = new cPlatformLevelStart(sf::Vector2f(x, y));
            mLevelPlatformList.AddPlayerSpawn(playerSpawn);
            std::cout << "Loaded player spawn point" << std::endl;
        }
    }
    else
    {
        // Add item offscreen
        cPlatformLevelStart* playerSpawn = new cPlatformLevelStart(sf::Vector2f(-500.f, -500.f));
        mLevelPlatformList.AddPlayerSpawn(playerSpawn);
        std::cout << "Added Default spawn point" << std::endl;
    }
}
*/