// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FLevelManager.h"
#include "FLevelManager.h"
#include "FTextureHolder.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>


FLevelManager::FLevelManager()
{
}


FLevelManager::~FLevelManager()
{
}

int32 FLevelManager::GetCurrentLevel() { return CurrentLevel; }

Vector2i FLevelManager::GetLevelSize() { return LevelSize; }

Vector2f FLevelManager::GetStartPosition() { return StartPosition; }

float FLevelManager::GetTimeLimit() { return BaseTimeLimit * TimeModifier; }

int32 ** FLevelManager::NextLevel(VertexArray& VertexArrayLevel)
{
	LevelSize.x = 0;
	LevelSize.y = 0;

	// Get Next Level
	CurrentLevel++;
	if (CurrentLevel > NUMBER_OF_LEVELS)
	{
		CurrentLevel = 1;
		TimeModifier -= .1f;
	}

	// Load the Appropriate Level from a Text File.
	string LevelToLoad;
	switch (CurrentLevel)
	{
	case 1:
		LevelToLoad = "Levels/level1.txt";
		StartPosition.x = 100;
		StartPosition.y = 100;
		BaseTimeLimit = 30.0f;
		break;

	case 2:
		LevelToLoad = "Levels/level2.txt";
		StartPosition.x = 100;
		StartPosition.y = 3600;
		BaseTimeLimit = 100.0f;
		break;

	case 3:
		LevelToLoad = "Levels/level3.txt";
		StartPosition.x = 1250;
		StartPosition.y = 0;
		BaseTimeLimit = 30.0f;
		break;

	case 4:
		LevelToLoad = "Levels/level4.txt";
		StartPosition.x = 50;
		StartPosition.y = 200;
		BaseTimeLimit = 50.0f;
		break;

	default:
		break;
	} // End Switch.


	ifstream LevelFile(LevelToLoad);
	string LevelRow;
	
	while (getline(LevelFile, LevelRow)) // Counts the Number of Rows in the File.
	{
		LevelSize.y++;
	}

	LevelSize.x = LevelRow.length();

	// Go Back to the Start of the File.
	LevelFile.clear();
	LevelFile.seekg(0, ios::beg);

	// Creates the 2D Array to Hold the Values from the File.
	int32** ArrayLevel = new int32*[LevelSize.y];
	for (int32 i = 0; i < LevelSize.y; i++)
	{
		ArrayLevel[i] = new int32[LevelSize.x];
	}

	// Loop through the File and Store ALL the Values in the 2D Array.
	//string Row;
	int32 y = 0;
	while (LevelFile >> LevelRow)
	{
		for (int32 x = 0; x < LevelRow.length(); x++)
		{
			const char Val = LevelRow[x];
			ArrayLevel[y][x] = atoi(&Val);
		}
		y++;
	}

	LevelFile.close(); // Closes the Level File.

	// Sets the Type of Primitive
	VertexArrayLevel.setPrimitiveType(Quads);

	// Sets the Size of the Vertex Array
	VertexArrayLevel.resize(LevelSize.x * LevelSize.y * VERTICES_IN_QUAD);

	int32 CurrentVertex = 0;
	for (int32 x = 0; x < LevelSize.x; x++)
	{
		for (int32 y = 0; y < LevelSize.y; y++)
		{
			// Position each Vertex in the Current Quad.
			VertexArrayLevel[CurrentVertex + 0].position = Vector2f(x * TILE_SIZE * 1.0f, y * TILE_SIZE * 1.0f);

			VertexArrayLevel[CurrentVertex + 1].position = Vector2f(TILE_SIZE * (x + 1) * 1.0f, y * TILE_SIZE * 1.0f);

			VertexArrayLevel[CurrentVertex + 2].position = Vector2f(TILE_SIZE * (x + 1) * 1.0f, TILE_SIZE * (y + 1) * 1.0f);

			VertexArrayLevel[CurrentVertex + 3].position = Vector2f(x * TILE_SIZE * 1.0f, TILE_SIZE * (y + 1) * 1.0f);

			// Defines the Tile from the Sprite Sheet 
			int32 VerticalOffset = ArrayLevel[y][x] * TILE_SIZE;

			VertexArrayLevel[CurrentVertex + 0].texCoords = Vector2f(0.0f, (0 + VerticalOffset) * 1.0f);

			VertexArrayLevel[CurrentVertex + 1].texCoords = Vector2f(TILE_SIZE * 1.0f, (0 + VerticalOffset)* 1.0f);

			VertexArrayLevel[CurrentVertex + 2].texCoords = Vector2f(TILE_SIZE * 1.0f, (TILE_SIZE + VerticalOffset) * 1.0f);

			VertexArrayLevel[CurrentVertex + 3].texCoords = Vector2f(0.0f, (TILE_SIZE + VerticalOffset) * 1.0f);

			CurrentVertex = CurrentVertex + VERTICES_IN_QUAD; // Reposition for the Next 4 Vertices.
		}
	}
	return ArrayLevel;
}
