// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void FEngine::Update(float DtAsSeconds)
{
	if (bIsPlaying)
	{
		// Counts Down the Time the Player has left.
		TimeRemaining -= DtAsSeconds; 

		if (TimeRemaining <= 0)
		{
			bIsNewLevelRequired = true;
		}
	} // Endif bIsPlaying
}
