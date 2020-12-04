#pragma once
#include "El_Position.h" 
#include "Texture.h"
#include <SDL.h>
#include <string>
#include <iostream>
#include <typeinfo>

class Base_Element
{
public:
	Base_Element(int x, int y, Rotate rotate = Rotate::Up, std::string texture_name = "Empty.bmp");
	virtual void Logic_Up_El(); // ������ ������ ��������
	virtual void Next_Update_El(); // �������� ����.
	virtual SDL_Texture* Draw(); // ���������� �������
	El_Position GetPosition() const;
	bool GetSignal() const;
protected:
	void Check_El(int x, int y, Rotate rotate); // ������� �� ������ 
	El_Position position;
	int sum_sig = 0;
	bool Signal = false;
};

