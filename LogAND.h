#pragma once
#include "Base_Element.h"
#include "Texture.h"

class LogAND :
    public Base_Element
{
public:
	LogAND(int x, int y, Rotate rotate) : Base_Element(x, y, rotate) { TEX->addTexture(typeid(this).name(), "Texture/LogAND.bmp"); }
	virtual void Logic_Up_El() override; // ������ ������ ��������
	virtual void Next_Update_El() override; // �������� ����.
	virtual SDL_Texture* Draw();
};

