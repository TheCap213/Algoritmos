#include <iostream>
#include "Animal.hpp"
#include "Diagnostico.hpp"
#include "Personal.hpp"
#include <conio.h>

void mostrarMenu() {
	cout << "\tMENU" << endl;
	cout << "1.Insertar Personal" << endl;
	cout << "2.Insertar Animal" << endl;
	cout << "3.Realizar Diagnostico" << endl;
	cout << "4.Reportes" << endl;
	cout << "5.Salir" << endl;
	cout << "Seleccione una opcion: ";
}

int main() {
	Animal* animales[50];
	Diagnostico* diagnosticos[100];
	Personal* personal[10];

	int numAnimales = 0, numDiagnosticos = 0, numPersonal = 0;
	int opc;

	do {
		system("cls");
		mostrarMenu();
		cin >> opc;

		switch (opc) {
		case 1: {
			string nombre, apellidos, fechaContratacion;
			cout << "Ingrese el nombre del personal: ";
			cin >> nombre;
			cout << "Ingrese los apellidos: ";
			cin >> apellidos;
			cout << "Ingrese la fecha de Contratacion: ";
			cin >> fechaContratacion;

			personal[numPersonal++] = new Personal(nombre, apellidos, fechaContratacion);
			cout << "Personal insertado correctamente." << endl;
			break;
		}
		case 2: {
			string tipo, nombre;
			int edad;
			cout << "Ingrese el tipo de animal: ";
			cin >> tipo;
			cout << "Ingrese el nombre del animal: ";
			cin >> nombre;
			cout << "Ingrese la edad del anima:";
			cin >> edad;

			animales[numAnimales++] = new Animal(tipo, nombre, edad);
			cout << "Animal insertado correctamente." << endl;
			break;

		}
		case 3: {
			string fecha, descripcion;
			cout << "Ingrese la fecha del diagnostico(YYYY-MM-DD): ";
			cin >> fecha;
			cout << "Ingrese la decripcion del diagnostico: ";
			cin >> descripcion;

			diagnosticos[numDiagnosticos++] = new Diagnostico(fecha, descripcion);
			cout << "Descripcion insertadad correctamente." << endl;
			break;

		}
		case 4: {
			cout << "Animales registrados: " << endl;
			for (int i = 0; i < numAnimales; i++) {
				animales[i]->mostrarAnimal();
			}

			cout << "\nDiagnosticos realizados: " << endl;
			for (int i = 0; i < numDiagnosticos; i++) {
				diagnosticos[i]->mostrarDiagnostico();
			}

			cout << "\nPersonal registrado:" << endl;
			for (int i = 0; i < numPersonal; i++) {
				personal[i]->mostrarPersonal();
			}
			break;
		}
		case 5:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion no valida." << endl;
			break;
		}

		_getch();
	} while (opc != 5);

	return 0;
}