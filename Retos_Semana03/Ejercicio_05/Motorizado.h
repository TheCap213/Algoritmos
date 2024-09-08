#pragma once 
#include <iostream>
#include <string>

using namespace std;

class Motorizado {
private:
	string Nombre;
	string Apellido;
	string Placa;
	int Kilometraje;
	string Empresa;
public:
	Motorizado(string nombre, string apellido, string placa, int kilometraje, string empresa) {
		Nombre = nombre;
		Apellido = apellido;
		Placa = placa;
		Kilometraje = kilometraje;
		Empresa = empresa;
	}
	~Motorizado(){}

	string getNombre() { return Nombre; }
	string getApellido() { return Apellido; }
	string getPlaca() { return Placa; }
	int getKilometraje() { return Kilometraje; }
	string getEmpresa() { return Empresa; }

	int Precio() { return Kilometraje * 1.5; }

};