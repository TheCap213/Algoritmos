#pragma once
#include <iostream>
#include <string>

using namespace std;

class Diagnostico {
private:
	string fecha;
	string descripcion;
public:
	Diagnostico(string fecha, string descripcion) {
		this->fecha = fecha;
		this->descripcion = descripcion;
	}

	string getFecha() { return fecha; }
	string getDescripcion() { return descripcion; }

	void mostrarDiagnostico() {
		cout << "Fecha: " << fecha << ", Descripcion: " << descripcion << endl;
	}

	~Diagnostico() {
		cout << "Diagnostico eliminado" << endl;
	}

};