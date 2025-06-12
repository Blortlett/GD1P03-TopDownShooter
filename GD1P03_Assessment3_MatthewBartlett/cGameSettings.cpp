/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cGameSettings]
Description : [This class holds app state data and allows swapping between main menu and gameplay mode]
Author : [Matthew Bartlett]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

#include "cGameSettings.h"

void cGameSettings::SetGameState(EGameState _GameState)
{

	mCurrentGameState = _GameState;
}
