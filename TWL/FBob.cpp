// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FBob.h"

FBob::FBob()
{
	CharacterSprite = Sprite(FTextureHolder::GetTexture("Graphics/bob.png"));

	JumpDuration = .25f;
}

FBob::~FBob()
{
}


bool FBob::HandleInput()
{
	bHasJustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up)) // Jumps
	{
		if (!bIsJumping && !bIsFalling)
		{
			bIsJumping = true;
			CurrentJumpDuration = 0;
			bHasJustJumped = true;
		}
	}
	else
	{
		bIsJumping = false;
		bIsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) // Move Right
	{
		bIsRightPressed = true;
	}
	else
	{
		bIsRightPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left)) // Move Left
	{
		bIsLeftPressed = true;
	}
	else
	{
		bIsLeftPressed = false;
	}

	return bHasJustJumped;
}
