#include "Cuenta.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	//Titulares
	Cuenta cuenta1("Johan");
	Cuenta cuenta2("Yonel", 500.0);

	cout << "Informacion de la cuenta 1:\n" << cuenta1.toString() << endl;
	cout << "Informacion de la cuenta 2:\n" << cuenta2.toString() << endl;

	//Ingreso de dinero en la cuenta 1
	cuenta1.ingresar(200.0);
	cout << "Despues de ingresar 200.0 a la cuenta 1:\n" << cuenta1.toString() << endl;

	//Retiro de dinero en la cuenta 2
	cuenta2.retirar(150.0);
	cout << "Despues de retirar 150.0 a la cuenta 2:\n" << cuenta2.toString() << endl;

	//Intentar retirar mas dinero de la cuenta 2
	cuenta2.retirar(450.0);
	cout << "Despues de intentar de retirar 450.0 de la cuenta 2:\n" << cuenta2.toString() << endl;

	_getch();
	system("pause");
	return 0;
}