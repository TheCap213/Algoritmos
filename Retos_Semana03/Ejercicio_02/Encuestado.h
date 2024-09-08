#pragma once
#include <iostream>
#include <string>

using namespace std;

class Encuestado {
private:
	int DNI;
	int leche;
public:
	Encuestado(int DNI, int leche) {
		this->DNI = DNI;
		this->leche = leche;
	}
	~Encuestado() {
	}

	int getDNI() {
		return DNI;
	}
	int getLeche() {
		return leche;
	}

};