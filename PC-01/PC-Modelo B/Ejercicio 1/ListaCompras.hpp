#pragma once
#include "Compra.hpp"

class ListaCompras {
private:
	Compra** compra;
	int numCompras;
public:
	ListaCompras() {
		numCompras = 0;
		compra = new Compra * [numCompras];
	}
	
	~ListaCompras() {
		for (int i = 0; i < numCompras; i++) {
			delete compra[i];
		}
		delete[] compra;
	}

	void AgregarCompra(Compra* c) {
		Compra** aux = new Compra * [numCompras + 1];
		for (int i = 0; i < numCompras; i++) {
			aux[i] = compra[i];
		}
		aux[numCompras] = c;
		numCompras++;

		if (compra != nullptr) delete[] compra;
		compra = aux;
	}

	void EliminarCompra(int ind) {
		if (ind < 0 || ind >= numCompras) {
			cout << "Numero de compra no encontrado..." << endl;
			return;
		}

		Compra** aux = new Compra * [numCompras - 1];
		for (int i = 0, j = 0; i < numCompras; i++) {
			if (i != ind) {
				aux[j++] = compra[i];
			}
		}
		delete compra[ind];
		delete[] compra;
		compra = aux;
		numCompras--;

		cout << "Compra eliminada exitosamente." << endl;
	}

	void MostrarListaCompras() {
		if (numCompras == 0) {
			cout << "No hay comrpas registradas." << endl;
			return;
		}

		cout << "Fecha\t\tCodCliente\tTipoCliente\tQ\tToral\tClubFidelizacion" << endl;
		for (int i = 0; i < numCompras; i++) {
			cout << compra[i]->getFecha() << "\t"
				<< compra[i]->getCodigoCliente() << "\t"
				<< compra[i]->getTipoCliente() << "\t\t"
				<< compra[i]->getCantidadProductos() << "\t"
				<< compra[i]->getTotal() << "\t"
				<< compra[i]->getClubFidelizacion() << endl;
		}
	}

	void ReporteTipoCliente(int tipo) {
		cout << "Fecha\t\tCodCliente\tTipoCliente\tQ\tToral\tClubFidelizacion" << endl;
		for (int i = 0; i < numCompras; i++) {
			if (compra[i]->getTipoCliente() == tipo) {
				compra[i]->MostrarCompra();
			}
		}
	}

	void ReporteClientesFidelizados() {
		cout << "Fecha\t\tCodCliente\tTipoCliente\tQ\tToral\tClubFidelizacion" << endl;
		for (int i = 0; i < numCompras; i++) {
			if (compra[i]->getClubFidelizacion() == 1) {
				compra[i]->MostrarCompra();
			}
		}
	}

};