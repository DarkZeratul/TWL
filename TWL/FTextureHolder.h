#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class FTextureHolder
{
public:
	FTextureHolder(); // Constructor
	~FTextureHolder(); // Destructor

	static sf::Texture& GetTexture(std::string const& filename);

private:
	// Holds Related Pairs of Strings and Textures.
	std::map<std::string, sf::Texture> StringToTextureMap;

	// The One and Only Instance: Singleton Design Pattern.
	static FTextureHolder* Instance;
};

#endif // TEXTURE_HOLDER_H
