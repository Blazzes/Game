#include "Start.h"
#include "Map.h"
extern Map* map;

Start::Start(int x, int y) : Base_Element(x, y, Rotate::All)
{
	TEX->addTexture(typeid(this).name(), "Texture/Start.bmp");
	Signal = true;
}

Start::~Start()
{
	Next_Update_El();
}

void Start::Logic_Up_El()
{
	std::cout << "update" << std::endl;
	//Logic_Up_El();
	//Next_Update_El();
}

void Start::Next_Update_El()
{
	map->GetElement(position.x(1), position.y())->Logic_Up_El();
	map->GetElement(position.x(-1), position.y())->Logic_Up_El();
	map->GetElement(position.x(), position.y(1))->Logic_Up_El();
	map->GetElement(position.x(), position.y(-1))->Logic_Up_El();
}
