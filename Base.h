#pragma once
#include<iostream>
#include<conio.h>
#include<vector>
#include<time.h>

using namespace std;
using namespace System;

#define WIDTH 120
#define HEIGHT 40

#define izquierda 75
#define derecha 77

class Base {
protected:
	int ID, x, y, dx, dy, height, width, status;
public:
	Base() {}
	virtual void draw() {} // Porque se usa en todo pero las otras clases lo hacen de manera distinta (Polimorfismo)
	virtual void move() {} // Porque se usa en todo pero las otras clases lo hacen de manera distinta (Polimorfismo)
	//virtual void moveM(int tecla){} 


	void clear() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}

	int getX() { return x; }
	int getY() { return y; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getID() { return ID; }
	int getStatus() { return status; }

};