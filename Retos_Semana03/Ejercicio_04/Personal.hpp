#pragma once
#include <iostream>
#include <string>

using namespace std;

class Personal {
private:
	string nombre;
	string apellidos;
	string fechaContratacion;
public: 
	Personal(string nombre, string apellidos, string fechaContratacion) {
		this->nombre = nombre;
		this->apellidos = apellidos;
		this->fechaContratacion = fechaContratacion;
	}

	string getNombre() { return nombre; }
	string getApellidos() { return apellidos; }
	string getFechaContratacion() { return fechaContratacion; }

	void mostrarPersonal() {
		cout << "Nombre: " << nombre << " " << apellidos << ", Fecha de Contratacion: " << fechaContratacion << endl;
	}

	~Personal() {
		cout << "Personal eliminado" << endl;
	}

};