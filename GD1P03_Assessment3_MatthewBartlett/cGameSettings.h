#pragma once

class cGameSettings
{
private:
	cGameSettings() {}
	~cGameSettings() {}

	bool mIsDebugModeActive = false;

public:

	// Get Is Debug Active
	bool IsDebugActive() { return mIsDebugModeActive; }
	void ToggleDebugMode() { mIsDebugModeActive = !mIsDebugModeActive; }







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