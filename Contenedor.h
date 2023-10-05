#pragma once
#include "Base.h"
#include "Corazon.h"
#include "Monigote.h"
#include "Trebol.h"
#include "Murcielago.h"

class Contenedor { //Es una composicion no una herencia
private:
	vector<Base*>vElementos; // Elemento hace referencia al Trebol y Corazon
	Monigote* oMonigote; // Creo el objeto Monigote
	Murcielago* oMurcielago; // Creo el objeto Murcielago
public:
	Contenedor() {
		oMonigote = new Monigote();
		oMurcielago = new Murcielago();
	}
	//Mover , borrar y dibujar monigote
	void clearM() {
		oMonigote->clear();
	}
	void moveM(int tecla) { 
		oMonigote->moveM(tecla);
	}
	void drawM() { 
		oMonigote->draw(); 
	}

	void generarElemento(Base *obj) {
		vElementos.push_back(obj);
	}

	void drawAll() {
		for (int i = 0; i < vElementos.size(); i++) {
			vElementos[i]->draw();
		}
		oMurcielago->draw();
	}

	void clearAll() {
		for (int i = 0; i < vElementos.size(); i++) {
			vElementos[i]->clear();
		}
		oMurcielago->clear();
	}

	void eliminarElemento(int pos) {
		vElementos.erase(vElementos.begin() + pos); // Se elimina
	}

	void moveAll() {
		for (int i = 0; i < vElementos.size(); i++) {
			vElementos[i]->move();
			//Para este if pongo el Status en Base
			if (vElementos[i]->getStatus() == 1)
				vElementos[i]->clear(); // Se borra
				eliminarElemento(i); // Se elimina
		}
		oMurcielago->move();
	}

	int getVidas() { return oMonigote->getVidas(); }
	int getCorazones() { return oMonigote->getCorazones(); }

	//Colision Monigote_Corazones
	void ColisionM_C() {
		if (vElementos.size() >= 1) { // Al menos 1 elemento tiene q aver para comenzar esto
		//Recorremos el vector buscando corazones
			for (int i = 0; i < vElementos.size(); i++) {
				if (vElementos[i]->getID() == 1) {
					int x1 = vElementos[i]->getX();
					int y1 = vElementos[i]->getY();
					int w1 = vElementos[i]->getWidth();
					int h1 = vElementos[i]->getHeight();
					
					int x2 = oMonigote->getX();
					int y2 = oMonigote->getY();
					int w2 = oMonigote->getWidth();
					int h2 = oMonigote->getHeight();

					if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2)) {
						//Aca se pone que es lo que se va a hacer tras efectuar la colicion de los dos
						vElementos[i]->clear(); 
						vElementos.erase(vElementos.begin() + i); 
						oMonigote->ganaVida(); 
						oMonigote->ganaCorazones();
					}
				}
			}
		}
	}

	//Colision Monigote Trebol
	void ColisionM_T() {
		if (vElementos.size() >= 1) { // Al menos 1 elemento tiene q aver para comenzar esto
		//Recorremos el vector buscando corazones
			for (int i = 0; i < vElementos.size(); i++) {
				if (vElementos[i]->getID() == 2) {
					int x1 = vElementos[i]->getX();
					int y1 = vElementos[i]->getY();
					int w1 = vElementos[i]->getWidth();
					int h1 = vElementos[i]->getHeight();

					int x2 = oMonigote->getX();
					int y2 = oMonigote->getY();
					int w2 = oMonigote->getWidth();
					int h2 = oMonigote->getHeight();

					if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2)) {
						//Aca se pone que es lo que se va a hacer tras efectuar la colicion de los dos
						vElementos[i]->clear(); // Lo limpia y lo reubica
						vElementos.erase(vElementos.begin() + i);
						oMonigote->clear(); // Borro monigote
						oMonigote->pierdeVidas();
					}
				}
			}
		}
	}

};