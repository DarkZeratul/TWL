// Adapted from the Lynda.com C++ Game Programming 2 Course.

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

