#include "FThomas.h"


FThomas::FThomas()
{
	CharacterSprite = Sprite(FTextureHolder::GetTexture("Graphics/thomas.png"));

	JumpDuration = .45f;
}


FThomas::~FThomas()
{
}


bool FThomas::HandleInput()
{
	bHasJustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W)) // Jumps
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

	if (Keyboard::isKeyPressed(Keyboard::D)) // Move Right
	{
		bIsRightPressed = true;
	}
	else
	{
		bIsRightPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) // Move Left
	{
		bIsLeftPressed = true;
	}
	else
	{
		bIsLeftPressed = false;
	}

	return bHasJustJumped;
}
