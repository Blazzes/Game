#pragma once
#include "Base_Element.h"
#include <typeinfo>
#include "Texture.h"

class Arrow :
    public Base_Element
{
public:
	Arrow(int x, int y, Rotate rotate);
	virtual void Logic_Up_El() override; // ������ ������ ��������
	virtual void Next_Update_El() override; // �������� ����.
	virtual SDL_Texture* Draw(); // ���������� �������
};

