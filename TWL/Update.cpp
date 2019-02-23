// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void FEngine::Update(float DtAsSeconds)
{
	if (bIsNewLevelRequired)
	{
		// Load a Level
		LoadLevel();
	}
	
	if (bIsPlaying)
	{
		// Update Thomas and Bob
		Thomas.Update(DtAsSeconds);
		Bob.Update(DtAsSeconds);

		// Detect Collisions and Check whether Thomas and Bob have reached the Goal.
		if (DetectCollisions(Thomas) && DetectCollisions(Bob))
		{
			bIsNewLevelRequired = true;

			// TODO: Play the Reached Goal Sound.
		}
		else
		{
			DetectCollisions(Bob);
		}

		// Allow Bob and Thomas to jump on each other Heads.
		if (Bob.GetFeet().intersects(Thomas.GetHead()))
		{
			Bob.StopFalling(Thomas.GetHead().top);
		}
		else if (Thomas.GetFeet().intersects(Bob.GetHead()))
		{
			Thomas.StopFalling(Bob.GetHead().top);
		}

		// Counts Down the Time the Player has left.
		TimeRemaining -= DtAsSeconds; 

		if (TimeRemaining <= 0)
		{
			bIsNewLevelRequired = true;
		}
	} // Endif bIsPlaying.

	// Sets the the Appropriate View around the Appropriate Character.
	if (bIsSplitScreen)
	{
		LeftView.setCenter(Thomas.GetCenter());
		RightView.setCenter(Bob.GetCenter());
	}
	else
	{
		// Center the Fullscreen around the Appropriate Character.
		if (bIsCharacter1Focused)
		{
			MainView.setCenter(Thomas.GetCenter());
		}
		else
		{
			MainView.setCenter(Bob.GetCenter());
		}
	}
}
