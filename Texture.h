#pragma once
#include <map>
#include <string>
#include <SDL.h>

#define TEX Texture::instance()

class Texture
{

public:
	static Texture* instance(){
		static Texture* inst = new Texture();
		return inst;
	}


	SDL_Texture* getTexture (std::string name){
		return m_texturesMap[name];
	}

	void addTexture(std::string name, std::string path);

private:
	Texture();
	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;
	Texture& operator=(const Texture&) = delete;
	std::map<std::string, SDL_Texture*> m_texturesMap;

};

