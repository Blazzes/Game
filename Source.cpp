#include "Base_Element.h"
#include "Map.h"
#include "El_Position.h"
#include "Includes.h"
#include <iostream>
#include <SDL.h>
#include <vector>
#include <string>

SDL_Window* win;
SDL_Renderer* ren;
Map* map;
SDL_Event e;

void init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
	map = new Map(1000, 1000);
}
void quit()
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

void draw_el(int el, Rotate rotate)
{
	switch (el)
	{
	case 1:
		map->Update_El_Map(new Arrow(0, 0, rotate));
		break;
	case 2:
		map->Update_El_Map(new LArrow(0, 0, rotate));
		break;
	case 3:
		map->Update_El_Map(new LogNOT(0, 0, rotate));
		break;
	case 4:
		map->Update_El_Map(new LogAND(0, 0, rotate));
		break;
	case 5:
		map->Update_El_Map(new BSignal(0, 0, rotate));
		break;
	case 6:
		map->Update_El_Map(new PSignal(0, 0, rotate));
		break;
	case 7:
		map->Update_El_Map(new LStart(0, 0));
		break;
	case 8:
		map->Update_El_Map(new Start(0, 0));
		break;
	}
}

int main(int argv, char* argc[])
{
	init();
	int elem_u = 1;
	int shift_x, shift_y;
	Rotate rt = Rotate::Up;
	bool Exit = true;
	std::cout << sizeof(Arrow) << std::endl;
	while (Exit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				Exit = false;
			}
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: 
					Exit = false;
					break;
				case SDLK_LEFT:
					map->SetShX(-1);
					break;
				case SDLK_RIGHT:
					map->SetShX(1);
					break;
				case SDLK_UP:
					map->SetShY(-1);
					break;
				case SDLK_DOWN:
					map->SetShY(1);
					break;
				case SDLK_r:
					rt = (Rotate)(((int)rt + 90) % 360);
					draw_el(elem_u, rt);
					break;
				case SDLK_1:
					elem_u = 1;
					draw_el(elem_u, rt);
					break;
				case SDLK_2:
					elem_u = 2;
					draw_el(elem_u, rt);
					break;
				case SDLK_3:
					elem_u = 3;
					draw_el(elem_u, rt);
					break;
				case SDLK_4:
					elem_u = 4;
					draw_el(elem_u, rt);
					break;
				case SDLK_5:
					elem_u = 5;
					draw_el(elem_u, rt);
					break;
				case SDLK_6:
					elem_u = 6;
					draw_el(elem_u, rt);
					break;
				case SDLK_7:
					elem_u = 7;
					draw_el(elem_u, rt);
					break;
				case SDLK_8:
					elem_u = 8;
					draw_el(elem_u, rt);
					break;
				}
			}
			if (e.type == SDL_MOUSEWHEEL)
			{
				if (e.wheel.y > 0) { //up
					if(El_Position::h() < 50) El_Position::h_Set(El_Position::h() * 2);
				}
				if (e.wheel.y < 0) { //up
					if(El_Position::h() > 20) El_Position::h_Set(El_Position::h() / 2);
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					int xMouse, yMouse, x, y;
					SDL_GetMouseState(&xMouse, &yMouse);
					x = trunc(xMouse / El_Position::h());
					y = trunc(yMouse / El_Position::h());
					switch (elem_u) {
					case 1:
						map->Update_El_Map(new Arrow(x, y, rt));
						break;
					case 2:
						map->Update_El_Map(new LArrow(x, y, rt));
						break;
					case 3:
						map->Update_El_Map(new LogNOT(x, y, rt));
						break;
					case 4:
						map->Update_El_Map(new LogAND(x, y, rt));
						break;
					case 5:
						map->Update_El_Map(new BSignal(x, y, rt));
						break;
					case 6:
						map->Update_El_Map(new PSignal(x, y, rt));
						break;
					case 7:
						map->Update_El_Map(new LStart(x, y));
						break;
					case 8:
						map->Update_El_Map(new Start(x, y));
						map->GetElement(x, y)->Next_Update_El();
						break;
					}
				}
				if (e.button.button == SDL_BUTTON_RIGHT)
				{
					int xMouse, yMouse, x, y;
					SDL_GetMouseState(&xMouse, &yMouse);
					x = trunc(xMouse / El_Position::h());
					y = trunc(yMouse / El_Position::h());
					map->Update_El_Map(new Base_Element(x, y,Rotate::Up, "Texture/Empty.bmp"));
					map->GetElement(x, y)->Next_Update_El();
				}
			}
		}
		map->Render();
	}
	quit();
	return 0;
}