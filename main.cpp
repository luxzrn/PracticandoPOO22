#include"Contenedor.h"
int main() {

	srand(time(NULL));

	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;

	Contenedor* oContenedor = new Contenedor(); // Me esta creando objetos en el vector

	//Invocar Vidas
	int v;
	//Invocar Corazones
	int c;

	int tiempoC = 0, tiempoT = 0;

	int x = 8;
	int y = 4;

	//Esto de aca me da  sys X y sus Y respectivos ya que no lo obtenemos de forma natural
	//int x = (((Murcielago*)oContenedor)->getWidth()) / 2;
	//int y = (((Murcielago*)oContenedor)->getWidth());

	do {
		//Arrojar Corazon
		if (tiempoC >= 10) {
			oContenedor->generarElemento(new Corazon(x,y));
			tiempoC = 0; // Lo vuelvo a inicializar
		}
		//Arrojar Treboles
		if (tiempoT >= 20) {
			oContenedor->generarElemento(new Trebol(x,y));
			tiempoT = 0; // Lo vuelvo a inicializar
		}

		//Limpiar Monigote
		oContenedor->clearM();

		//Mover Monigote
		if (kbhit()) {
			int tecla = getch();
			if (tecla == 224) {//Key down
				tecla = getch();
				oContenedor->moveM(tecla);
			}
		}
		//Dibujo el Monigote
		oContenedor->drawM();

		//Continuo con los demas objetos
		oContenedor->clearAll();
		oContenedor->moveAll();
		oContenedor->drawAll();

		oContenedor->ColisionM_C();
		oContenedor->ColisionM_T();

		tiempoC++;
		tiempoT++;

		
		v = oContenedor->getVidas(); // Me actualiza el valor
		Console::SetCursorPosition(WIDTH -10,35);
		cout << "Vidas: " << v ;
		c = oContenedor->getCorazones(); // Me actualiza el valor
		Console::SetCursorPosition(WIDTH - 14, 36);
		cout << "Corazones: " << c ;
		Console::SetCursorPosition(WIDTH - 14, 34);
		_sleep(100);

	} while (v > 0);

	system("cls");
	Console::SetCursorPosition(WIDTH / 2 -35, HEIGHT / 2);
	cout << "Cantidad de corazones obtenidos: " << oContenedor->getCorazones() << endl;
	system("pause=0"); // Me pausea la pantalla

}