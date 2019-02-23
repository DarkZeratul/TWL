// Adapted from the Lynda.com C++ Game Programming 2 Course.

#pragma once
#ifndef FPlayableCharacter_H
#define FPlayableCharacter_H

#include <SFML/Graphics.hpp>

using namespace sf;

class FPlayableCharacter
{
public:
	FPlayableCharacter();
	~FPlayableCharacter();

	FloatRect GetPosition();
	FloatRect GetFeet();
	FloatRect GetHead();
	FloatRect GetRight();
	FloatRect GetLeft();
	Sprite GetSprite();

	void Spawn(Vector2f, float);

	// Pure Virtual Function - Override NOT Optional
	bool virtual HandleInput() = 0; 

	// Prevents the Character from Falling Through a Solid Tile.
	void StopFalling(float);
	// Prevents the Character from Walking (Right) Through a Solid Tile.
	void StopRight(float);
	// Prevents the Character from Walking (Left) Through a Solid Tile.
	void StopLeft(float);
	// Prevents the Character from Jumping Through a Solid Tile.
	void StopJump();

	Vector2f GetCenter();

	void Update(float);

protected:
	Sprite CharacterSprite;

	bool bIsJumping;
	bool bIsFalling;

	bool bIsLeftPressed;
	bool bIsRightPressed;

	float JumpDuration; // How Long a Jump Last.
	float CurrentJumpDuration; // How Long the Current Jump has Lasted.
	// Has the Player just Started a Jump? - To Play Jump Sound Effect.
	bool bHasJustJumped = false;

private:
	float Gravity;

	float Speed = 400;

	Vector2f Position; // Center of the Character.

	// Character Body Parts
	FloatRect BodyFeet;
	FloatRect BodyHead;
	FloatRect BodyRight;
	FloatRect BodyLeft;

	Texture CharacterTexture;
};
#endif // FPlayableCharacter_H