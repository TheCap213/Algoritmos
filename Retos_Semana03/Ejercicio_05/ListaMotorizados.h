#pragma once 
#include "Motorizado.h"

class ListaMotorizados {
private:
	Motorizado** listaMot;
	int nMot;
public:
	ListaMotorizados() {
		nMot = 0;
		listaMot = new Motorizado * [nMot];
	}
	~ListaMotorizados() {
		for (int i = 0; i < nMot; i++) {
			delete listaMot[i];
		}
		delete[] listaMot;
	}

	void AgregarMotorizado(Motorizado* m) {
		Motorizado** aux = new Motorizado * [nMot + 1];
		for (int i = 0; i < nMot; i++) {
			aux[i] = listaMot[i];
		}
		aux[nMot] = m;
		nMot++;

		if (listaMot != nullptr) delete[] listaMot;
		listaMot = aux;
	}

	void EliminarMotorizado(int ind) {
		if (ind < 0 || ind >= nMot) {
			cout << "Motoriazdo no encontrado..." << endl;
			return;
		}

		Motorizado** aux = new Motorizado * [nMot - 1];
		for (int i = 0, j = 0; i < nMot; i++) {
			if (i != ind) {
				aux[j++] = listaMot[i];
			}
		}

		delete listaMot[ind];
		delete[] listaMot;
		listaMot = aux;
		nMot--;

		cout << "Motorizado eliminado exitosamente." << endl;
	}

	void MostrarMotorizados() {
		if (nMot == 0) {
			cout << "No hay motorizados registrados." << endl;
			return;
		}

		cout << "\tNombre\tApellido\tPlaca\tKilometraje\tPrecio\Empresa";
		for (int i = 0; i < nMot; i++) {
			cout << endl << "\t" 
				<< listaMot[i]->getNombre() << "\t"
				<< listaMot[i]->getApellido() << "\t""\t"
				<< listaMot[i]->getKilometraje() << "\t"
				<< listaMot[i]->Precio() << "\t""\t"
				<< listaMot[i]->getEmpresa() << endl;
		}
	}

	void MotorizadosMapi() {
		bool found = false;
		cout << "\tNombre\tApellido\tKilometraje\tPrecio\tEmpresa";
		for (int i = 0; i < nMot; i++) {
			if (listaMot[i]->getEmpresa() == "Mapi" || listaMot[i]->getEmpresa() == "mapi") {
				found = true;
				cout << endl << "\t"
					<< listaMot[i]->getNombre() << "\t"
					<< listaMot[i]->getApellido() << "\t""\t"
					<< listaMot[i]->getKilometraje() << "\t"
					<< listaMot[i]->Precio() << "\t""\t"
					<< listaMot[i]->getEmpresa();
			}
		}
		if (!found) {
			cout << "No hay Motorizados de la empresa Mapi." << endl;
		}

	}

	void MotorizadosGlopo() {
		bool found = false;
		cout << "\tNombre\tApellido\tKilometraje\tPrecio\tEmpresa";
		for (int i = 0; i < nMot; i++) {
			if (listaMot[i]->getEmpresa() == "Glopo" || listaMot[i]->getEmpresa() == "glopo") {
				found = true;
				cout << endl << "\t"
					<< listaMot[i]->getNombre() << "\t"
					<< listaMot[i]->getApellido() << "\t""\t"
					<< listaMot[i]->getKilometraje() << "\t"
					<< listaMot[i]->Precio() << "\t""\t"
					<< listaMot[i]->getEmpresa();
			}
		}
		if (!found) {
			cout << "No hay Motorizados de la empresa Glopo." << endl;
		}
	}
};