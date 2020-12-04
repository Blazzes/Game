#pragma once
#include "Base_Element.h"
class LArrow :
    public Base_Element
{
public:
    LArrow(int x, int y, Rotate rotate) : Base_Element(x, y, rotate) { TEX->addTexture(typeid(this).name(), "Texture/LArrow.bmp"); }
    virtual void Logic_Up_El() override; // логика работы элемента
    virtual void Next_Update_El() override; // обновить след.
    virtual SDL_Texture* Draw();
};

