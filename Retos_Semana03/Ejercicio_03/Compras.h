#pragma once
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Compra {
private:
	int idCompra;
	string fecha;
	Cliente* cliente;
	Producto** productos;
	int numProductos;
public:
	Compra(int idCompra, string fecha, Cliente* cliente) {
		this->idCompra = idCompra;
		this->fecha = fecha;
		this->cliente = cliente;
		this->productos = nullptr;
		this->numProductos = 0;
	}
	~Compra() {
		delete[] productos;
	}

	void agregarProducto(Producto* producto) {
		Producto** aux = new Producto * [numProductos + 1];
		for (int i = 0; i < numProductos; i++) {
			aux[i] = productos[i];
		}
		aux[numProductos] = producto;
		if (productos != nullptr) {
			delete[] productos;
		}
		productos = aux;
		numProductos++;
	}

	void mostrarCompra() {
		cout << "ID Compra: " << idCompra << ", Fecha: " << fecha << endl;
		cliente->mostrarCliente();
		cout << "Productos comprados:" << endl;
		for (int i = 0; i < numProductos; i++) {
			productos[i]->mostrarProducto();
		}
	}
};