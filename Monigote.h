#pragma once
#include "Base.h"

class Monigote :public Base {
protected:
	int vidas;
	int corazones;
public:
	Monigote() {
		x = rand() % (WIDTH - width);
		y = HEIGHT - height; // El ancho de la pantalla menos el ancho del monigote
		dx = 0;
		dy = 0;
		width = 3;
		height = 3;
		vidas = 1;
		corazones = 0;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::DarkCyan;
		Console::SetCursorPosition(x, y + 0); cout << " ° ";
		Console::SetCursorPosition(x, y + 1); cout << "|";
		Console::SetCursorPosition(x, y + 2); cout << " | ";
	}

	void moveM(int tecla) {
		switch (tecla)
		{
		case izquierda: dx = -1; dy = 0;
			break;
		case derecha: dx = 1; dy = 0;
			break;
		}

		if (x + dx < 0 || x + dx + width > WIDTH) {
			dx *= -1; //Rebote y movimiento
		}

		x += dx;

	}

	int getVidas() { return vidas; }
	int getCorazones() { return corazones; }
	void pierdeVidas() { vidas--;  x = 60; y = HEIGHT - height; dx = 0; dy = 0; } // Lo X u Y son para que cuando pierda vidas vuelvan a esa posicion
	void ganaVida() { vidas++; }
	void ganaCorazones() { corazones++; } //Contador
};