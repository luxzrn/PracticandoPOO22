#pragma once
#include "Base.h"

class Corazon : public Base {

	//int  ID;
	//int status; // Para saber si llega al final y de borre
public:
	Corazon(int px, int py) {
		x = px;
		y = py;
		dx = 0;
		dy = 1 + rand() % 4; //La velocidad y direccion
		height = 1;
		width = 1;
		ID = 1;
		status = 0;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << char(3); //Icono de el corazon
	}

	void move() {
		if (y + dy + height >= HEIGHT) { // Comprueba que no sale de abajo porque solo se va para abajo
			status = 1; // Llego a la parte final y debe ser borrado del vector
			dy = 0; // Para que no siga avanzando
		}
		y += dy;
	}

	int getID() { return ID; }
	int getStatus() { return status; }


};