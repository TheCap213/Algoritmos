#include "ListaMotorizados.h"
#include <conio.h>

using namespace System;

int Menu() {
	int op;
	do {
		cout << endl << "\MENU" << endl;
		cout << "1.Agregar motorizado" << endl;
		cout << "2.Eliminar motorizado" << endl;
		cout << "3.Motrotrar todos los motorizados" << endl;
		cout << "4.Motorizados Mapi" << endl;
		cout << "5.Motorizados Glopo" << endl;
		cout << "Seleccione una opción: "; cin >> op;
	} while (op < 1 || op > 5);
	return op;
}

void PresionaContinuar() {
	cout << endl << "Presiona una tecla para continuar...";
	_getch();
}

int main() {
	setlocale(LC_ALL, "");

	Motorizado* motorizado;
	ListaMotorizados* arregloM = new ListaMotorizados();

	int op;
	int ind;
	string Nombre;
	string Apellido;
	string Placa;
	int Kilometraje;
	string Empresa;

	while (true) {
		system("cls"); 
		op = Menu();

		switch (op) {
		case 1:
			cout << endl << "Ingrese los datos del motorizado" << endl;
			cout << "Nombre: "; cin >> Nombre;
			cout << "Apellido: "; cin >> Apellido;
			cout << "Placa: "; cin >> Placa;
			cout << "Kilometraje: "; cin >> Kilometraje;
			cout << "Empresa: "; cin >> Empresa;

			motorizado = new Motorizado(Nombre, Apellido, Placa, Kilometraje, Empresa);
			arregloM->AgregarMotorizado(motorizado);
			PresionaContinuar();
			break;
		case 2:
			cout << "Ingrese el indice del motorizado a eliminar: ";
			cin >> ind;
			arregloM->EliminarMotorizado(ind);
			PresionaContinuar();
			break;
		case 3:
			arregloM->MostrarMotorizados();
			PresionaContinuar();
			break;
		case 4:
			arregloM->MotorizadosMapi();
			PresionaContinuar();
			break;
		case 5:
			arregloM->MotorizadosGlopo();
			PresionaContinuar();
			break;


		}
	}
	delete arregloM;
	_getch();
	return 0;
}

