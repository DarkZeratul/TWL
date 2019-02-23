// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FPlayableCharacter.h"


FPlayableCharacter::FPlayableCharacter()
{
}

FPlayableCharacter::~FPlayableCharacter()
{
}


FloatRect FPlayableCharacter::GetPosition() { return CharacterSprite.getGlobalBounds(); }

FloatRect FPlayableCharacter::GetFeet() { return BodyFeet; }
FloatRect FPlayableCharacter::GetHead() { return BodyHead; }
FloatRect FPlayableCharacter::GetRight() { return BodyRight; }
FloatRect FPlayableCharacter::GetLeft() { return BodyLeft; }

Sprite FPlayableCharacter::GetSprite() { return CharacterSprite; }

Vector2f FPlayableCharacter::GetCenter()
{
	return Vector2f(Position.x + CharacterSprite.getGlobalBounds().width / 2,
		Position.y + CharacterSprite.getGlobalBounds().height / 2);
}


void FPlayableCharacter::Spawn(Vector2f StartPosition, float GameGravity)
{
	Position.x = StartPosition.x;
	Position.y = StartPosition.y;

	Gravity = GameGravity;

	CharacterSprite.setPosition(Position); // Move the Character Sprite in to Position.	
}

void FPlayableCharacter::StopFalling(float StopPosition)
{
	Position.y = StopPosition - GetPosition().height;
	CharacterSprite.setPosition(Position);
	bIsFalling = false;
}

void FPlayableCharacter::StopRight(float StopPosition)
{
	Position.x = StopPosition - CharacterSprite.getGlobalBounds().width;
	CharacterSprite.setPosition(Position);
}

void FPlayableCharacter::StopLeft(float StopPosition)
{
	Position.x = StopPosition + CharacterSprite.getGlobalBounds().width;
	CharacterSprite.setPosition(Position);
}

void FPlayableCharacter::StopJump()
{
	bIsJumping = false;
	bIsFalling = true;
}

void FPlayableCharacter::Update(float ElapsedTime)
{
	// Handles Moving Right.
	if (bIsRightPressed)
	{
		Position.x += Speed * ElapsedTime;
	}

	// Handles Moving Left.
	if (bIsLeftPressed)
	{
		Position.x -= Speed * ElapsedTime;
	}

	// Handles Jumping
	// TODO: Create SpeedY and Adapt this Section.
	if (bIsJumping)
	{
		CurrentJumpDuration += ElapsedTime;

		if (CurrentJumpDuration < JumpDuration)
		{
			Position.y -= Gravity * 2 * ElapsedTime;
		}
		else
		{
			bIsJumping = false;
			bIsFalling = true;
		}
	}

	// Applies Gravity if the Character is falling.
	if (bIsFalling)
	{
		Position.y += Gravity * ElapsedTime;
	}

	// Update de Rect for ALL Body Parts.
	FloatRect Body = GetPosition();

	// Feet
	BodyFeet.left = Body.left + 3;
	BodyFeet.top = Body.top + Body.height - 1;
	BodyFeet.width = Body.width - 6;
	BodyFeet.height = 1;

	// Head
	BodyHead.left = Body.left;
	BodyHead.top = Body.top + (Body.height * .3f);
	BodyHead.width = Body.width;
	BodyHead.height = 1;

	//Right
	BodyRight.left = Body.left + Body.width - 2;
	BodyRight.top = Body.top + (Body.height * .35f);
	BodyRight.width = 1;
	BodyRight.height = Body.height * .3f;

	//Left
	BodyLeft.left = Body.left;
	BodyLeft.top = Body.top + (Body.height * .5f);
	BodyLeft.width = 1;
	BodyLeft.height = Body.height * .3f;

	CharacterSprite.setPosition(Position); // Move the Character Sprite in to Position.	
}