#include "ListaEncuestados.h"
#include <conio.h>

void mostrarMenu() {
	cout << "\MENU" << endl;
	cout << "1.Generar Encuestados" << endl;
	cout << "2.Mostrar Encuestados" << endl;
	cout << "3.Eliminar Encuestados" << endl;
	cout << "4.Salir" << endl;
	cout << "Seleccione una opcion: ";
}

int main() {
	ListaEncuestados lista;
	int opc;
	do {
		system("cls");
		mostrarMenu();
		cin >> opc;

		switch (opc) {
		case 1:
			lista.generarEncuestados();
			cout << "Encuestado generado correctamente." << endl;
			break;
		case 2:
			lista.mostrarEncuestados();
			break;
		case 3:
			int dni;
			cout << "Ingrese el DNI del encuestado a eliminar: ";
			cin >> dni;
			lista.eliminarEncuestado(dni);
			break;
		case 4:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "opcion no valida. Intente de nuevo." << endl;
			break;
		}

		if (opc != 4) {
			cout << "Presione cualquier tecla para continuar...";
		}
	} while (opc != 4);

	return 0;
}