#include "FTextureHolder.h"
#include <assert.h>

using namespace std;
using namespace sf;

FTextureHolder* FTextureHolder::Instance = nullptr;

FTextureHolder::FTextureHolder()
{
	assert(Instance == nullptr);
	
	Instance = this;	
}

FTextureHolder::~FTextureHolder()
{
}

sf::Texture& FTextureHolder::GetTexture(std::string const& filename)
{
	auto& StringToTextureMap = Instance->StringToTextureMap; // Auto is Equivalent to map<string, Texture>

	auto KeyValuePair = StringToTextureMap.find(filename); // Auto is Equivalent to map<string, Texture>::iterator

	if (KeyValuePair != StringToTextureMap.end())
	{
		return KeyValuePair->second; // File Found: Returns the Texture
	}
	else
	{
		auto& Texture = StringToTextureMap[filename]; // File Not Found: Creates a New Key Value Pair Using the File's Name

		Texture.loadFromFile(filename);

		return Texture;
	}
}
