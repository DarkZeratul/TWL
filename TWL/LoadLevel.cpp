#include "FEngine.h"

void FEngine::LoadLevel()
{
	
	bIsPlaying = false;

	// Deallocate the previously allocated memory.
	for (int32 i = 0; i < LevelManager.GetLevelSize().y; i++)
	{
		delete[] ArrayLevel[i];
	}
	delete[] ArrayLevel;

	// Loads and Repopulate the Next 2D Array w/ the Map for the Level
	ArrayLevel = LevelManager.NextLevel(VertexArrayLevel);

	TimeRemaining = LevelManager.GetTimeLimit();

	// Sets Thomas and Bob Spawn's Position.
	Thomas.Spawn(LevelManager.GetStartPosition(), GRAVITY);
	Bob.Spawn(LevelManager.GetStartPosition(), GRAVITY);

	bIsNewLevelRequired = false; 
}