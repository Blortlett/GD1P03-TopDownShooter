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
#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "cBaseLevel.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class cFileInterface
{
public:
	cFileInterface(cBaseLevel* _CurrentLevel);
	~cFileInterface();
	void SaveLevelDialog();
	void LoadLevelDialog();
	void LoadLevelByName(const std::string& levelName);

private:
	cBaseLevel* mCurrentLevel;

	// Helper methods for file dialogs
	bool ShowFileSaveDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt);
	bool ShowFileOpenDialog(std::wstring& outFilePath, const wchar_t* fileTypeDesc, const wchar_t* fileTypeExt);

	// Core file operations
	void SaveLevelToFile(const std::wstring& filePath);
	void LoadLevelFromFile(const std::wstring& filePath);

	// JSON saving helpers
	void SaveFullWallCollidersToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	void SaveHalfWallCollidersToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);
	//void SavePlayerSpawnToJson(rapidjson::Document& doc, rapidjson::Document::AllocatorType& allocator);

	// JSON loading helpers
	void LoadFullWallColidersFromJson(const rapidjson::Document& doc);
	void LoadHalfWallColidersFromJson(const rapidjson::Document& doc);
	//void LoadPlayerSpawnFromJson(const rapidjson::Document& doc);
};