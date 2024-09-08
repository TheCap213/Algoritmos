#pragma once
#include <iostream>
using namespace std;

class Fecha {
private:
	int dia, mes, anio;
public:
	// Constructor por defecto con valores aleatorios
	Fecha() {
		this->dia = rand() % 29 + 1;
		this->mes = rand() % (2) + 5;
		this->anio = rand() % (2030 - 2000 + 1) + 2000;
	}
	// Constructor con parámetros específicos
	Fecha(int dia, int mes, int anio) {
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	// Destructor
	~Fecha() {};

	// Setters
	void setDia(int dia) {
		this->dia = dia;
	}
	void setMes(int mes) {
		this->mes = mes;
	}
	void setAnio(int anio) {
		this->anio = anio;
	}

	// Getters
	int getDia() {
		return this->dia;
	}
	int getMes() {
		return this->mes;
	}
	int getAnio() {
		return this->anio;
	}

	void mostrarFecha() {
		cout << dia << "/" << mes << "/" << anio << endl;
	}
};