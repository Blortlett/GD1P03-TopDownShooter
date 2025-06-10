#pragma once

enum class EGameState
{
	MainMenu,
	Gameplay
};

class cGameSettings
{
private:
	cGameSettings() { mCurrentGameState = EGameState::MainMenu;  }
	~cGameSettings() {}

	// Main Menu or Gameplay
	EGameState mCurrentGameState;

	// Pause Menu
	bool mIsGamePaused = false;
	// Options Menu
	bool mIsOptionsMenuOpen = false;
	// Debug Menu
	bool mIsDebugMenuOpen = false;

	// Debug Mode
	bool mIsDebugModeActive = false;


public:
	// -= Main Menu / Gameplay State=-
	// Get / Set game state (Main menu or Gameplay)
	EGameState GetGameState() { return mCurrentGameState; }
	void SetGameState(EGameState _GameState) { mCurrentGameState = _GameState; }


	// -= Debug Mode =-
	// Get/Set Is Debug Active
	bool IsDebugActive() { return mIsDebugModeActive; }
	void ToggleDebugMode() { mIsDebugModeActive = !mIsDebugModeActive; }


	// -= Pause Menu Stuff =-
	// Get paused state
	bool GetIsGamePaused() { return mIsGamePaused; }
	// Toggle pause
	void ToggleGamePaused() 
	{ 
		mIsGamePaused = !mIsGamePaused;
		// If not paused, ensure options & debug menu is disabled
		if (mIsGamePaused == false)
		{
			mIsDebugMenuOpen = false;
			mIsOptionsMenuOpen = false;
		}
	}
	// Specifically set pause
	void ToggleGamePaused(bool _Toggle) 
	{ 
		// Set pause state
		mIsGamePaused = _Toggle;
		// If not paused, ensure options & debug menu is disabled
		if (_Toggle == false)
		{
			mIsDebugMenuOpen = false;
			mIsOptionsMenuOpen = false;
		}
	}

	// -= Options Menu =-
	// Get Options state
	bool GetIsOptionsMenuOpen() { return mIsOptionsMenuOpen; }
	// Open/Close Options menu
	void ToggleOptionsMenu(bool _Toggle) { mIsOptionsMenuOpen = _Toggle; }

	// -= Debug Menu =-
	// Get Debug state
	bool GetIsDebugMenuOpen() { return mIsDebugMenuOpen; }
	// Open/Close Debug menu
	void ToggleDebugMenu(bool _Toggle) { mIsDebugMenuOpen = _Toggle; }
	// Debug Vars
	bool mIsGodModeActive = false;
	bool mIsInfiniteAmmoActive = false;




	// Singleton crap....
	// Get the single instance of the class
	static cGameSettings& GetInstance()
	{
		static cGameSettings instance; // Static instance created on first call
		return instance;
	}
	// Delete copy constructor and assignment operator to prevent copying
	cGameSettings(const cGameSettings&) = delete;
	cGameSettings& operator=(const cGameSettings&) = delete;
};