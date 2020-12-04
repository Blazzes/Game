#pragma once
#include "Base_Element.h"
class PSignal :
    public Base_Element
{
public:
	PSignal(int x, int y, Rotate rotate) : Base_Element(x, y, rotate) { TEX->addTexture(typeid(this).name(), "Texture/PSignal.bmp"); }
	virtual void Logic_Up_El() override; // логика работы элемента
	virtual void Next_Update_El() override; // обновить след.
	virtual void Check_El(int x, int y, Rotate rotate);
	virtual SDL_Texture* Draw();
};

