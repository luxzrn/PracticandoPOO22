#pragma once
#include "Base.h"

class Trebol : public Base {

	//int ID;
	//int status;
public:
	Trebol(int px, int py) {
		x = px;
		y = py;
		dx = 0;
		dy = 1 + rand() % 4;
		height = 1;
		width = 1;
		ID = 2;
		status = 0;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y); cout << char(5);
	}

	void move() {
		if (y + dy + height >= HEIGHT) {
			status = 1;
			dy = 0;
		}
		y += dy;
	}

	int getID() { return ID; }
	int getStatus() { return status; }


};