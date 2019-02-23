// Adapted from the Lynda.com C++ Game Programming 2 Course.

#pragma once
#ifndef FLEVELMANAGER_H
#define FLEVELMANAGER_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

using int32 = int;

class FLevelManager
{
public:
	FLevelManager();
	~FLevelManager();

	const int32 TILE_SIZE = 50;
	const int32 VERTICES_IN_QUAD = 4;

	int32 GetCurrentLevel();
	Vector2i GetLevelSize();
	Vector2f GetStartPosition();
	int32** NextLevel(VertexArray&);

	float GetTimeLimit();


private:
	const int32 NUMBER_OF_LEVELS = 4;
	int CurrentLevel = 0;
	Vector2i LevelSize;
	Vector2f StartPosition;

	float TimeModifier = 1.0f;
	float BaseTimeLimit = 0.0f;
};
#endif // FLEVELMANAGER_H
