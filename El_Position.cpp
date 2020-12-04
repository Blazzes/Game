#include "El_Position.h"
#include "Map.h"
extern Map* map;
int El_Position::h_ = 20;
int El_Position::x(int z) const { return (x_ + z) % map->GetX(); }
int El_Position::y(int u) const { return (y_ + u) % map->GetY(); }
void El_Position::h_Set(int h) { h_ = h; }
int El_Position::h() { return h_; }
Rotate El_Position::rotate() const { return rotate_; }
El_Position::El_Position(int x, int y, Rotate rotate) :x_(x), y_(y), rotate_(rotate) {}