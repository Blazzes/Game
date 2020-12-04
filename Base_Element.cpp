#include "Base_Element.h"
#include "Map.h"
#include "Includes.h"

extern Map* map;
extern SDL_Renderer* ren;

El_Position Base_Element::GetPosition() const
{
	return position;
}

bool Base_Element::GetSignal() const
{
	return Signal;
}

SDL_Texture* Base_Element::Draw()
{
	return Signal ? TEX->getTexture("ON") : TEX->getTexture(typeid(this).name());
}

void Base_Element::Next_Update_El()
{
	if(map->GetElement(position.x(1), position.y())->GetPosition().rotate() != Rotate::Left) map->GetElement(position.x(1), position.y())->Logic_Up_El();
	if (map->GetElement(position.x(-1), position.y())->GetPosition().rotate() != Rotate::Right) map->GetElement(position.x(-1), position.y())->Logic_Up_El();
	if (map->GetElement(position.x(), position.y(1))->GetPosition().rotate() != Rotate::Up) map->GetElement(position.x(), position.y(1))->Logic_Up_El();
	if (map->GetElement(position.x(), position.y(-1))->GetPosition().rotate() != Rotate::Down) map->GetElement(position.x(), position.y(-1))->Logic_Up_El();
}

void Base_Element::Logic_Up_El() {}

void Base_Element::Check_El(int x, int y, Rotate rotate)
{
	Base_Element* el = map->GetElement(x, y);
	if (dynamic_cast<LArrow*>(map->GetElement(position.x((position.x() - x) * 2), position.y((position.y() - y) * 2))) &&
		map->GetElement(position.x((position.x() - x) * 2), position.y((position.y() - y) * 2))->GetSignal() == true &&
		map->GetElement(position.x((position.x() - x) * 2), position.y((position.y() - y) * 2))->GetPosition().rotate() != rotate)
	{
		sum_sig++;
	}
	if (el->GetPosition().rotate() == Rotate::All &&
		el->GetSignal() == true)
	{
		sum_sig += 5;
	}
	if (dynamic_cast<BSignal*>(el) &&
		el->GetPosition().rotate() == rotate &&
		el->GetSignal() == true)
	{
		sum_sig = -10;
	}
	if (el->GetPosition().rotate() == rotate &&
		el->GetSignal() == true)
	{
		sum_sig++;
	}
}

Base_Element::Base_Element(int x, int y, Rotate rotate, std::string texture_name) : position(x, y, rotate)
{
	TEX->addTexture(typeid(this).name(), texture_name);
	/*texture = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP(texture_name.c_str()));
	if(texture == nullptr) std::cout << SDL_GetError() << std::endl;
	texture_on = SDL_CreateTextureFromSurface(ren, SDL_LoadBMP("Texture/ON.bmp"));
	if (texture == nullptr) std::cout << SDL_GetError() << std::endl;*/
}