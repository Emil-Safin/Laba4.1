#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

using namespace System::Drawing;

class Circle {
private:
	int x, y, radius;
	bool selected;
public:
	Circle() :x(0), y(0), radius(0), selected(true) {}
	Circle(int x, int y, int r) :x(x), y(y), radius(r), selected(true) {}
	void draw(System::Windows::Forms::PaintEventArgs^ e) {
		System::Drawing::Brush^ brsh = Brushes::Blue;
		if (selected)
			brsh = Brushes::Red;
		e->Graphics->FillEllipse(brsh, x - (radius / 2), y - (radius / 2), radius, radius);
	}
	bool checkCollision(int x, int y) {
		if ((this->x - (radius / 2) <= x) && (this->x + (radius / 2) >= x))
			if ((this->y - (radius / 2) <= y) && (this->y + (radius / 2) >= y))
				return true;
			else
				return false;
		else
			return false;
	}
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetRadius(int r) { this->radius = r; }
	void SetSelect(bool s = true) { this->selected = s; }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
	int GetRadius() { return this->radius; }
	bool GetSelect() { return this->selected; }
};

#endif
