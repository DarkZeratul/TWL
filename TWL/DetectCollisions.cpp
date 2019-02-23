#include "FEngine.h"

bool FEngine::DetectCollisions(FPlayableCharacter& Character)
{
	bool bHasReachedGoal = false;

	// Creates a Rectangle for ALL the Character's Parts.
	FloatRect DetectionZone = Character.GetPosition();

	FloatRect Block;
	Block.width = TILE_SIZE * 1.0f;
	Block.height = TILE_SIZE * 1.0f;

	// Creates a Collision Detection Zone around the Character.
	int32 StartX = int32(DetectionZone.left / TILE_SIZE) - 1;
	int32 StartY = int32(DetectionZone.top / TILE_SIZE - 1);
	int32 EndX = int32(DetectionZone.left / TILE_SIZE + 2);
	int32 EndY = int32(DetectionZone.top / TILE_SIZE + 3); // Thomas

	// Detect Collision against the Boundaries of the Level.
	if (StartX < 0) StartX = 0;
	if (StartY < 0) StartY = 0;
	if (EndX >= LevelManager.GetLevelSize().x) EndX = LevelManager.GetLevelSize().x;
	if (EndY >= LevelManager.GetLevelSize().y) EndY = LevelManager.GetLevelSize().y;

	// Handle the Player Falling out of the Level.
	FloatRect Level(0, 0,
		LevelManager.GetLevelSize().x * TILE_SIZE * 1.0f,
		LevelManager.GetLevelSize().y * TILE_SIZE * 1.0f);
	if (!Character.GetPosition().intersects(Level))
	{
		Character.Spawn(LevelManager.GetStartPosition(), GRAVITY * 1.0f);
	}

	for (int32 x = StartX; x < EndX; x++)
	{
		for (int32 y = StartY; y < EndY; y++)
		{
			// Initialize the Starting Position of the Current Block
			Block.left = x * TILE_SIZE *1.0f;
			Block.top = y * TILE_SIZE * 1.0f;

			// Check if the Character has been burnt or drowned
			if (ArrayLevel[y][x] == 2 || ArrayLevel[y][x] == 3)
			{
				if (Character.GetHead().intersects(Block))
				{
					// Get the Specific Sound for the Situation
					if (ArrayLevel[y][x] == 2) // Fire
					{
						// TODO: Play Sound.
					}
					else // Water
					{
						// TODO: Play Sound.
					}
				}
			}

			// Check if the Character is Colliding w/ a Regular Block
			if (ArrayLevel[y][x] == 1)
			{
				if (Character.GetRight().intersects(Block))
				{
					Character.StopRight(Block.left);
				}
				else if (Character.GetLeft().intersects(Block))
				{
					Character.StopLeft(Block.left);
				}

				if (Character.GetFeet().intersects(Block))
				{
					Character.StopFalling(Block.top);
				}
				else if (Character.GetHead().intersects(Block))
				{
					Character.StopJump();
				}
			}

			// TODO: Apply Collision Detection related to Particle Effects

			// Check if the Character has reached the Goal.
			if (ArrayLevel[y][x] == 4)
			{
				bHasReachedGoal = true;
			}
		}
	}
	return bHasReachedGoal;
}