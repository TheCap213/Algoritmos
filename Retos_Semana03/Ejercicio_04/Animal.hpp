#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
	string tipo;
	string nombre;
	int edad;
public:
	Animal(string tipo, string nombre, int edad) {
		this->tipo = tipo;
		this->nombre = nombre;
		this->edad = edad;
	}
	
	void mostrarAnimal() {
		cout << "Ripo: " << ", Nombre: " << nombre << ", Edad: " << edad << " anios" << endl;
	}

	~Animal() {
		cout << "Animal eliminado." << endl;
	}
};