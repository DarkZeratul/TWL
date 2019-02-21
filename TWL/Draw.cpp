// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"

void FEngine::Draw()
{
	Window.clear(Color::White);

	if (bIsSplitScreen) // Splitscreen
	{
		// Draw Thomas' Side of the Screen (Left)
		Window.setView(BgLeftView);
		Window.draw(BgSprite);
		Window.setView(LeftView);

		// Draw Bob and Thomas on the Right Side of the Screen
		Window.draw(Bob.GetSprite());
		Window.draw(Thomas.GetSprite());

		// Draw Bob's Side of the Screen (Right)
		Window.setView(BgRightView);
		Window.draw(BgSprite);
		Window.setView(RightView);

		// Draw Thomas and Bob on the Left Side of the Screen
		Window.draw(Thomas.GetSprite());
		Window.draw(Bob.GetSprite());
	}
	else // Fullscreen
	{
		Window.setView(BgMainView);
		Window.draw(BgSprite);
		Window.setView(MainView);

		// Draw Thomas and Bob
		Window.draw(Thomas.GetSprite());
		Window.draw(Bob.GetSprite());
	}

	Window.setView(HudView); //Draw the HUD

	Window.display();
}