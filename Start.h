#pragma once
#include "Base_Element.h"

class Start :
    public Base_Element
{
public:
	Start(int x, int y);
	~Start();
	virtual void Logic_Up_El() override; // ������ ������ ��������
	virtual void Next_Update_El() override; // �������� ����.
};

