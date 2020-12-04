#include "LStart.h"
#include "Includes.h"
#include "Map.h"

extern Map* map;

void LStart::Logic_Up_El()
{
	Check_El(position.x(2), position.y(), Rotate::Left);
	Check_El(position.x(-2), position.y(), Rotate::Right);
	Check_El(position.x(), position.y(2), Rotate::Up);
	Check_El(position.x(), position.y(-2), Rotate::Down);
	std::cout << __FILE__ << std::endl;
	Signal = sum_sig > 0;
	sum_sig = 0;
	Next_Update_El();
}

void LStart::Check_El(int x, int y, Rotate rotate)
{
	Base_Element* el = map->GetElement(x, y);
	if (el->GetSignal() && el->GetPosition().rotate() == rotate &&
		dynamic_cast<LArrow*>(el))
	{
		sum_sig++;
	}
}

SDL_Texture* LStart::Draw()
{
	return Signal ? TEX->getTexture("ON") : TEX->getTexture(typeid(this).name());
}

LStart::LStart(int x, int y, Rotate rotate) : Base_Element(x, y, rotate)
{
	TEX->addTexture(typeid(this).name(), "Texture/LStart.bmp");
}