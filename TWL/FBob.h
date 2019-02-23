// Adapted from the Lynda.com C++ Game Programming 2 Course.

#pragma once
#include "FPlayableCharacter.h"
#include "FTextureHolder.h"

class FBob :
	public FPlayableCharacter
{
public:
	FBob();
	~FBob();

	bool virtual HandleInput(); //Overriden Handler for Bob.
};

