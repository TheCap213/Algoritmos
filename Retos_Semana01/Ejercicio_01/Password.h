#pragma once
#include <iostream>

using namespace std;

class Contrasena {
private: 
	int longitud;
	char* password;
public:
	Contrasena() {
		this->longitud = 8;
		this->password = nullptr;
		generarContrasena();
	}
	Contrasena(int longitud) {
		this->longitud = longitud;
		this->password = nullptr;
		generarContrasena();
	}
	~Contrasena() {
	}

	void generarContrasena() {
		char c;
		this->password = new char[this->longitud];
		for (int i = 0; i < this->longitud; i++) {
			do {
				c = rand() % (122 - 48 + 1) + 48;
			} while ((c >= 58 && c <= 64) || (c >= 91 && c <= 96));
			this->password[i] = c;
		}
	}
	bool esSeguro() {
		int cntMayus, cntMinus, cntNumeros;
		cntMayus = cntMinus = cntNumeros = 0;
		for (int i = 0; i < this->longitud; i++) {
			if (this->password[i] >= 'A' && this->password[i] <= 'Z') {
				cntMayus++;
			}
			if (this->password[i] >= 'a' && this->password[i] <= 'z') {
				cntMinus++;
			}
			if (this->password[i] >= '0' && this->password[i] <= '9') {
				cntNumeros++;
			}
		}
		return (cntMayus > 2 && cntMinus > 1 && cntNumeros > 5);
	}
	int getLongitud() {
		return this->longitud;
	}
	char *getContrasena() {
		return this->password;
	}
	void imprimirContrasenaSeguro() {
		for (int i = 0; i < this->longitud; i++) {
			cout << password[i];
		}
		cout << ": Fuerte: ";
		if (esSeguro()) {
			cout << "V";
		}
		else {
			cout << "F";
		}
		cout << endl;
	}
	void setLongitud(int longitud) {
		this->longitud = longitud;
	}
};