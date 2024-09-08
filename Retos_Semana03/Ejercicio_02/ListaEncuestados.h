#pragma once
#include "Encuestado.h"
#include <cstdlib>
#include <ctime>

class ListaEncuestados {
private:
	Encuestado** encuestados;
	int numEncuestados;
public:
	ListaEncuestados() {
		numEncuestados = 0;
		encuestados = new Encuestado * [numEncuestados];
	}
	
	~ListaEncuestados() {
		for (int i = 0; i < numEncuestados; i++) {
			delete encuestados[i];
		}
		delete[] encuestados;
	}

	void generarEncuestados() {
		srand(time(NULL));
		
		int DNI = rand() % 90000000 + 10000000;
		int leche = rand() % 4 + 1;

		Encuestado* nuevoEncuestado = new Encuestado(DNI, leche);

		agregarEncuestado(nuevoEncuestado);
	}

	void agregarEncuestado(Encuestado* nuevoEncuestado) {
		Encuestado** aux = new Encuestado * [numEncuestados + 1];
		for (int i = 0; i < numEncuestados; i++) {
			aux[i] = encuestados[i];
		}
		aux[numEncuestados] = nuevoEncuestado;
		if (encuestados != nullptr) delete[] encuestados;
		encuestados = aux;
		numEncuestados++;
	}

	void mostrarEncuestados() {
		if (numEncuestados == 0) {
			cout << "No hay encuestados registrados..." << endl;
			return;
		}

		cout << "DNI\t\tLeche" << endl;
		for (int i = 0; i < numEncuestados; i++) {
			cout << encuestados[i]->getDNI() << "\t" << encuestados[i]->getLeche() << endl;
		} 
	}

	void eliminarEncuestado(int dni) {
		int indice = -1;
		for (int i = 0; i < numEncuestados; i++) {
			if (encuestados[i]->getDNI() == dni) {
				indice = i;
				break;
			}
		}

		if (indice == -1) {
			cout << "No se encontró un encuestado con el DNI " << dni << endl;
			return;
		}

		delete encuestados[indice];
		Encuestado** aux = new Encuestado * [numEncuestados - 1];
		for (int i = 0, j = 0; i < numEncuestados; i++) {
			if (i != indice) {
				aux[j++] = encuestados[i];
			}
		}
		delete[] encuestados;
		encuestados = aux;
		numEncuestados--;

		cout << "Encuestado eliminado exitosamente." << endl;
	}
};


