// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"

void FEngine::Draw()
{
	Window.clear(Color::White);

	if (bIsSplitScreem) // Splitscreen
	{
		// Draw Thomas' Side of the Screen (Left)
		Window.setView(BgLeftView);
		Window.draw(BgSprite);
		Window.setView(LeftView);

		// Draw Bob's Side of the Screen (Left)
		Window.setView(BgRightView);
		Window.draw(BgSprite);
		Window.setView(RightView);

		Window.setView(HudView); //Draw the HUD
	}
	else // Fullscreen
	{
		Window.setView(BgMainView);
		Window.draw(BgSprite);
		Window.setView(MainView);
	}

	Window.display();
}