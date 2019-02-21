// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"

void FEngine::Input()
{
	Event GameEvent;

	while (Window.pollEvent(GameEvent))
	{
		if (GameEvent.type == Event::KeyPressed)
		{
			// Handle the Player Quitting the Game
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				Window.close();
			}

			// Handle the Player Starting the Game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				bIsPlaying = true;
			}

			// Switch between Thomas and Bob
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				bIsCharacter1Focused = !bIsCharacter1Focused;
			}

			// Switch between Fullscreen and Splitscreen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				bIsSplitScreen = !bIsSplitScreen;
			}
		}
	}

	// Handle Thomas' Inputs
	if (Thomas.HandleInput())
	{
		// TODO: Thomas Jump Sound
	}

	// Handle Bob's Inputs
	if (Bob.HandleInput())
	{
		// TODO: Bob Jump Sound
	}
}