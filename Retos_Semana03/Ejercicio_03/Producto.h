#pragma once
#include <iostream>
using namespace std;

class Producto {
	int codProducto;
	string nombre;
	string tipo;
	string marca;
	int cantidad;
	double precio;
public:
	Producto(int codProducto, string nombre, string tipo, string marca, int cantidad, double precio) {
		this->codProducto = codProducto;
		this->nombre = nombre;
		this->tipo = tipo;
		this->marca = marca;
		this->cantidad = cantidad;
		this->precio = precio;
	}

	int getCodProducto() { return codProducto; }
	string getNombre() { return nombre; }
	string getTipo() { return tipo; }
	string getMarca() { return marca; }
	int getCantidad() { return cantidad; }
	double getPrecio() { return precio; }

	void setCantidad(int cantidad) { this->cantidad = cantidad; }
	void setPrecio(double precio) { this->precio = precio; }

	void mostrarProducto() {
		cout << "Codigo: " << codProducto << ", Nombre: " << nombre << ", Tipo: " << tipo
			<< ", Marca: " << marca << ", Cantidad: " << cantidad << ", Precio: S/" << precio << endl;
	}
};