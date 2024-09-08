#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
	string titular;
	double cantidad;

public:
	Cuenta(string titular) {
		this->titular = titular;
		this->cantidad = 0.0;
	}

	Cuenta(string titular, double cantidad) {
		this->titular = titular;
		this->cantidad = cantidad;
	}

	~Cuenta() {}

	//Ingresar dinero 
	void ingresar(double cantidad) {
		if (cantidad > 0) {
			this->cantidad += cantidad;
		}
	}

	//Retirar dinero 
	void retirar(double cantidad) {
		if (cantidad > 0) {
			this->cantidad -= cantidad;
			if (this->cantidad < 0) {
				this->cantidad = 0.0;
			}
		}
	}

	string getTitular() {
		return titular;
	}

	double getCantidad() {
		return cantidad;
	}

	void setTitular(string titular) {
		this->titular = titular;
	}

	void setCantidad(double cantidad) {
		this->cantidad = cantidad;
	}

	string toString() {
		return "Titular: " + titular + "\nCantidad: " + to_string(cantidad) + "\n";
	}
};