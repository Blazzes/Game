#pragma once
#include "Base_Element.h"
class LStart :
    public Base_Element
{
public:
	LStart(int x, int y, Rotate rotate = Rotate::All);
	virtual void Logic_Up_El() override; // логика работы элемента
	virtual void Check_El(int x, int y, Rotate rotate);
	virtual SDL_Texture* Draw(); // отрисовать элемент
};

