#pragma once

class cGameSettings
{
private:
	cGameSettings() {}
	~cGameSettings() {}

	bool mIsGamePaused = false;
	bool mIsDebugModeActive = false;

public:

	// Get/Set Is Debug Active
	bool IsDebugActive() { return mIsDebugModeActive; }
	void ToggleDebugMode() { mIsDebugModeActive = !mIsDebugModeActive; }

	// Get paused state
	bool GetIsGamePaused() { return mIsGamePaused; }
	// Toggle pause
	void ToggleGamePaused() { mIsGamePaused = !mIsGamePaused; }
	// Specifically set pause
	void ToggleGamePaused(bool _Toggle) { mIsGamePaused = _Toggle; }







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