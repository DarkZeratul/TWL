// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void FEngine::Update(float DtAsSeconds)
{
	if (bIsNewLevelRequired)
	{
		// Spawn Thomas and Bob
		Thomas.Spawn(Vector2f(0,0), GRAVITY);
		Bob.Spawn(Vector2f(100, 0), GRAVITY);

		TimeRemaining = 10;
		bIsNewLevelRequired = false;
	}
	
	if (bIsPlaying)
	{
		// Update Thomas and Bob
		Thomas.Update(DtAsSeconds);
		Bob.Update(DtAsSeconds);

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
