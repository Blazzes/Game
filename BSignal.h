#pragma once
#include "Base_Element.h"
class BSignal :
    public Base_Element
{
public:
	BSignal(int x, int y, Rotate rotate) : Base_Element(x, y, rotate) { TEX->addTexture(typeid(this).name(), "BSignal.bmp"); }
	virtual void Logic_Up_El() override; // логика работы элемента
	virtual void Next_Update_El() override; // обновить след.
	virtual SDL_Texture* Draw(); // отрисовать элемент
};

