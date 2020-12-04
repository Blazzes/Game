#include "PSignal.h"
#include "Map.h"
extern Map* map;

void PSignal::Check_El(int x, int y, Rotate rotate)
{
	if (map->GetElement(x, y)->GetSignal()) sum_sig++;
}

void PSignal::Logic_Up_El()
{
	if(position.rotate() == Rotate::Left) Check_El(position.x(1), position.y(), Rotate::Left);
	if (position.rotate() == Rotate::Right) Check_El(position.x(-1), position.y(), Rotate::Right);
	if (position.rotate() == Rotate::Up) Check_El(position.x(), position.y(1), Rotate::Up);
	if (position.rotate() == Rotate::Down) Check_El(position.x(), position.y(-1), Rotate::Down);
	std::cout << __FILE__ << std::endl;
	Signal = sum_sig > 0;
	sum_sig = 0;
	map->Render();
	Next_Update_El();
}

void PSignal::Next_Update_El()
{
	switch (position.rotate()) {
	case Rotate::Right:
		if (map->GetElement(position.x(1), position.y())->GetPosition().rotate() != Rotate::Left) map->GetElement(position.x(1), position.y())->Logic_Up_El();
		break;
	case Rotate::Left:
		if (map->GetElement(position.x(-1), position.y())->GetPosition().rotate() != Rotate::Right) map->GetElement(position.x(-1), position.y())->Logic_Up_El();
		break;
	case Rotate::Down:
		if (map->GetElement(position.x(), position.y(1))->GetPosition().rotate() != Rotate::Up) map->GetElement(position.x(), position.y(1))->Logic_Up_El();
		break;
	case Rotate::Up:
		if (map->GetElement(position.x(), position.y(-1))->GetPosition().rotate() != Rotate::Down) map->GetElement(position.x(), position.y(-1))->Logic_Up_El();
		break;
	}
}

SDL_Texture* PSignal::Draw()
{
	return Signal ? TEX->getTexture("ON" + (std::string)typeid(this).name()) : TEX->getTexture(typeid(this).name());
}