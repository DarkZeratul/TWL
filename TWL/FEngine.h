// Adapted from the Lynda.com C++ Game Programming 2 Course.

#pragma once
#ifndef FENGINE_H
#define FENGINE_H

#include <SFML/Graphics.hpp>
#include "FTextureHolder.h"
#include "FThomas.h"
#include "FBob.h"
#include "FLevelManager.h"

using namespace sf;

// Unreal Friendly Syntax
using int32 = int;

class FEngine
{
public:
	FEngine(); // Constructor.
	~FEngine();

	void Run();

private:
	FTextureHolder TextureHolder;

	FThomas Thomas;
	FBob Bob;

	FLevelManager LevelManager;

	const int32 TILE_SIZE = 50;
	const int32 VERTICES_IN_QUAD = 4;

	const int32 GRAVITY = 300;

	RenderWindow Window; // Regular RenderWindow.

	// Main Views.
	View MainView;	// Fullscreen
	View LeftView;	// L. Splitscreen
	View RightView;	// R. Splitscreen

	// Background Views.
	View BgMainView;	// Fullscreen
	View BgLeftView;	// L. Splitscreen
	View BgRightView;	// R. Splitscreen

	View HudView;

	// Background Sprite and Texture.
	Sprite BgSprite;
	Texture BgTexture;

	bool bIsPlaying = false; // Keeps Track whether the Level has started.

	// Keeps Track whether Character 1 is focused. False = Character 2 is focused.
	bool bIsCharacter1Focused = true; // Fullscreen Only.

	bool bIsSplitScreen = false; // Starts in Full Screen Mode.

	// Keep Track of the Time Left in the Current Level.
	float TimeRemaining = 10;
	Time GameTotalTime;

	// Keeps Track whether a New Level is required.
	bool bIsNewLevelRequired = true;

	// Vertex Array for the Level Design.
	VertexArray VertexArrayLevel;

	// 2D Array w/ the Map for the Level.
	int32** ArrayLevel = NULL;

	// Texture for the Background and Level Tiles.
	Texture TextureTiles;

	void Input();
	void Update(float);
	void Draw();

	void LoadLevel(); // Loads a New Level

	bool DetectCollisions(FPlayableCharacter&); // Polymorphism
}; 
#endif // FENGINE_H

