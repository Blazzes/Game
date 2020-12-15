#include "Map.h"
Map::Map(int x, int y): map_w(x), map_h(y)
{
	for (int y_ = 0; y_ < y; ++y_)
	{
		std::vector<Base_Element*> row;
		for (int x_ = 0; x_ < x; ++x_)
		{
			row.push_back(new Base_Element(x_, y_));
		}
		Element.push_back(row);
	}
}

void Map::Update_El_Map(Base_Element* el)
{
	Base_Element* tmp = Element[el->GetPosition().y()][el->GetPosition().x()];
	Element[el->GetPosition().y()][el->GetPosition().x()] = el;
	//tmp->Logic_Up_El();
	el->Logic_Up_El();
	delete tmp;
}

void Map::Render()
{
	/*int _x, _y, _h;
	int X, Y;
	SDL_RenderClear(ren);
	int dsp_y, dsp_x;
	SDL_GetWindowSize(win, &dsp_x, &dsp_y);
	_h = El_Position::h();
	for (int y_ = 0; y_ < dsp_y / _h; ++y_)
	{
		for (int x_ = 0; x_ < dsp_x / _h; ++x_)
		{
			X = (x_ + x_shift) % x;
			Y = (y_ + y_shift) % y;
			_x = Element[Y][X]->GetPosition().x();
			_y = Element[Y][X]->GetPosition().y();
			
			SDL_Rect r;
			r.x = (_x - X) * _h;
			r.y = (_y - Y)* _h;
			r.h = r.w = _h;
			SDL_RenderCopyEx(ren, Element[Y][X]->Draw(), NULL, &r, (int)Element[Y][X]->GetPosition().rotate(), NULL, SDL_FLIP_NONE);
		}
	}
	SDL_RenderPresent(ren);*/

	SDL_Rect r;
	int start_x_dr, start_y_dr, disp_w, disp_h, El_h, El_x, El_y;
	El_h = El_Position::h();
	SDL_GetWindowSize(win, &disp_w, &disp_h);
	SDL_RenderClear(ren);
	for (int y = y_shift; y < (disp_h / El_h)+ y_shift; ++y)
	{
		for (int x = x_shift; x < (disp_w / El_h) + x_shift; ++x)
		{
			El_x = GetElement(x, y)->GetPosition().x() - x_shift;
			El_y = GetElement(x, y)->GetPosition().y() - y_shift;
			r.x = El_x * El_h;
			r.y = El_y * El_h;
			r.w = r.h = El_h;
			SDL_RenderCopyEx(ren, GetElement(x, y)->Draw(), NULL, &r, GetElement(x, y)->GetPosition().rotate(), NULL, SDL_FLIP_NONE);
		}
	}
	SDL_RenderPresent(ren);
}

Base_Element* Map::GetElement(int x_, int y_) const {
	return Element[abs(y_ + map_h) % map_h][abs(x_ + map_w) % map_w];
}