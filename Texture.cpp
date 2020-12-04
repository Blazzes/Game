#include "Texture.h"
#include <iostream>
extern SDL_Renderer* ren;

Texture::Texture(){
	m_texturesMap["ON"] = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP("Texture/ON.bmp"));
}

void Texture::addTexture(std::string C_Name, std::string T_Name){
	auto it = m_texturesMap.begin(); 

	for (int i = 0; it != m_texturesMap.end(); it++, i++) {  // выводим их
		if (it->first == C_Name)
		return;
    }
	std::string ON_CName = "ON" + C_Name;
	std::string ON_TName = "ON" + T_Name;
	m_texturesMap[C_Name] = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP(("Texture/" + T_Name).c_str()));
	m_texturesMap[ON_CName] = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP(("Texture/" + ON_TName).c_str()));
	std::cout << C_Name << "  " << T_Name << "  " << ON_CName << "  " << ON_TName << "  " << ("Texture/" + T_Name).c_str() << std::endl;
}