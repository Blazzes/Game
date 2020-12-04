#pragma once
#include "Base_Element.h"
#include <vector>
#include <SDL.h>

extern SDL_Renderer* ren;
extern SDL_Window* win;

class Map
{
public:
	Map(int x, int y);
	void Render();
	//void Render(Base_Element el);
	void Update_El_Map(Base_Element* element = nullptr);
	Base_Element* GetElement(int x, int y) const;
	int GetX() const { return map_w; }
	int GetY() const { return map_h; }
	void SetShX(int X) { x_shift += X; }
	void SetShY(int Y) { y_shift += Y; }

private:
	int map_w, map_h, x_shift = 0, y_shift = 0;
	//SDL_Renderer* ren;
	std::vector<std::vector<Base_Element*>> Element;
};

