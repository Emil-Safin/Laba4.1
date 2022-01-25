#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
//#include <cmath>
using namespace System::Drawing;

class Circle {
private:
	int x, y, diametr;
	bool selected;
public:
	Circle() :x(0), y(0), diametr(0), selected(true) {}
	Circle(int x, int y, int r) :x(x), y(y), diametr(r), selected(true) {}
	void draw(System::Windows::Forms::PaintEventArgs^ e) {
		System::Drawing::Brush^ brsh = Brushes::Blue;
		if (selected)
			brsh = Brushes::Red;
		e->Graphics->FillEllipse(brsh, x - (diametr / 2), y - (diametr / 2), diametr, diametr);
	}
	bool checkCollision(int x, int y) {
		if (((x - this->x) * (x - this->x)) + (y - this->y) * ((y - this->y)) <= (diametr/2 * diametr/2)){
			return true;
		}
		else
			return false;
	}
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void Setdiametr(int r) { this->diametr = r; }
	void SetSelect(bool s = true) { this->selected = s; }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
	int Getdiametr() { return this->diametr; }
	bool GetSelect() { return this->selected; }
};

#endif
