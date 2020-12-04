#pragma once
enum Rotate {
	Up = 0, Right = 90, Down = 180, Left = 270, All = 360
};
class El_Position
{
public:
	El_Position(int x = 0, int y = 0, Rotate rotate = Rotate::Up);
	int x(int z = 0) const;
	int y(int u = 0) const;
	static int h();
	static void h_Set(int h);
	Rotate rotate() const;
private:
	Rotate rotate_;
	int x_, y_;
	static int h_;
};

