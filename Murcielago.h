#pragma once
#include "Base.h"

class Murcielago :public Base {
public:
	Murcielago() {
		x = 0;
		y = 0;
		dx = 1 + rand() % 3;
		dy = 0;
		width = 16;
		height = 4;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y + 0); cout << "  _   ,_,  _   ";
		Console::SetCursorPosition(x, y + 1); cout << " / ´'=) (='´  \\";
		Console::SetCursorPosition(x, y + 2); cout << "/.-.-. \/ .-.- \\";
		Console::SetCursorPosition(x, y + 3); cout << " ´     ''     ´";

	}

	void move() {
		//Va solo de izquierda a derecha por lo tanto solo validamos eso 
		if (x + dx <0 || x + dx + width > WIDTH)
			dx *= -1;
		x += dx;
	}

};