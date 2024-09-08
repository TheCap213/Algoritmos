#pragma once
#include <iostream>
using namespace std;

class Cliente {
private:
	string dni;
	string nombre;
public:
	Cliente(string dni, string nombre) {
		this->dni = dni;
		this->nombre = nombre;
	}

	string getDNI() { return dni; }
	string getNombre() { return nombre; }

	void mostrarCliente() {
		cout << "DNI: " << dni << ", Nombre: " << nombre << endl;
	}

};