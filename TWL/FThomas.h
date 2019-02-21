#pragma once
#include "FPlayableCharacter.h"
#include "FTextureHolder.h"

class FThomas :
	public FPlayableCharacter
{
public:
	FThomas();
	~FThomas();

	bool virtual HandleInput(); //Overriden Handler for Thomas.
};

