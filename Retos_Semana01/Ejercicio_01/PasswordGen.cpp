
#include "Password.h"
#include <conio.h>

int main() {
	srand(time(nullptr));
	int numero;
	numero = rand() % 8 + 2;

	bool* sonFuertes = new bool[numero];
	Contrasena** contra = new Contrasena * [numero];

	for (int i = 0; i < numero; i++) {
		contra[i] = new Contrasena(rand() % (25 - 5 + 1) + 5);
	}
	for (int i = 0; i < numero; i++) {
		contra[i]->imprimirContrasenaSeguro();
	}
	delete contra;
	delete sonFuertes;
	_getch();
	system("pause");
	return 0;
}
