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

