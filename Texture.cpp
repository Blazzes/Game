#include "Texture.h"

extern SDL_Renderer* ren;

Texture::Texture(){
	m_texturesMap["ON"] = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP("Texture/ON.bmp"));
}

void Texture::addTexture(std::string name, std::string path){
	auto it = m_texturesMap.begin(); 

	for (int i = 0; it != m_texturesMap.end(); it++, i++) {  // выводим их
		if (it->first == name)
		return;
    }
	m_texturesMap[name] = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP(path.c_str()));
}