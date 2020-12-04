#include "LogNOT.h"
#include "Map.h"
extern Map* map;

void LogNOT::Logic_Up_El()
{
	Check_El(position.x(1), position.y(), Rotate::Left);
	Check_El(position.x(-1), position.y(), Rotate::Right);
	Check_El(position.x(), position.y(1), Rotate::Up);
	Check_El(position.x(), position.y(-1), Rotate::Down);
	Signal = !(sum_sig > 0);
	std::cout << __FILE__ << std::endl;
	sum_sig = 0;
	Next_Update_El();
}

void LogNOT::Next_Update_El()
{
	switch (position.rotate()) {
	case Rotate::Right:
		map->GetElement(position.x(1), position.y())->Logic_Up_El();
		break;
	case Rotate::Left:
		map->GetElement(position.x(-1), position.y())->Logic_Up_El();
		break;
	case Rotate::Down:
		map->GetElement(position.x(), position.y(1))->Logic_Up_El();
		break;
	case Rotate::Up:
		map->GetElement(position.x(), position.y(-1))->Logic_Up_El();
		break;
	}
}

SDL_Texture* LogNOT::Draw()
{
	return Signal ? TEX->getTexture("ON") : TEX->getTexture(typeid(this).name());
}