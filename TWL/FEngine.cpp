// Adapted from the Lynda.com C++ Game Programming 2 Course.

#include "FEngine.h"

FEngine::FEngine()
{
	Vector2f Resolution;
	Resolution.x = VideoMode::getDesktopMode().width;
	Resolution.y = VideoMode::getDesktopMode().height;

	Window.create(VideoMode(Resolution.x, Resolution.y), "Thomas Was Late", Style::Resize);

	// Initialize the Fullscreen View
	MainView.setSize(Resolution);
	HudView.reset(FloatRect(0, 0, Resolution.x, Resolution.y));

	// Initialize the Splitscreen Views: Assigns a Portion of the Screen to a SFML View Object
	LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	BgLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	BgRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	BgTexture = FTextureHolder::GetTexture("Graphics/background.png");

	BgSprite.setTexture(BgTexture); // Associate the Sprite with the Texture.
}


FEngine::~FEngine()
{
}

void FEngine::Run()
{
	Clock GameClock;

	while (Window.isOpen())
	{
		Time Dt = GameClock.restart(); // Delta Time.

		GameTotalTime += Dt; // Updates the Game Total Time.

		float DtAsSeconds = Dt.asSeconds(); // Delta Time in Seconds.

		// Call each Part of the Game Loop in Turn
		Input();
		Update(DtAsSeconds);
		Draw();
	}
}
