#pragma once
#include "Proveedor.hpp"

class Producto {
private:
	int idProducto;
	string nombre;
	string tipo;
	int cantidad;
	char categoria;
	int anio;
	double precio;
	Proveedor* proveedor;
public:
	Producto(int idProducto, string nombre, string tipo, int cantidad, char categoria, int anio, double precio, Proveedor* proveedor) {
		this->idProducto = idProducto;
		this->nombre = nombre;
		this->tipo = tipo;
		this->cantidad = cantidad;
		this->categoria = categoria;
		this->anio = anio;
		this->precio = precio;
		this->proveedor = proveedor;
	}

	int getIdProducto() { return idProducto; }
	string getNombre() { return nombre; }
	string getTipo() { return tipo; }
	int getCantidad() { return cantidad; }
	char getCategoria() { return categoria; }
	int getAnio() { return anio; }
	double getPrecio() { return precio; }
	Proveedor* getProveedor() { return proveedor; }

	void setCantidad(int catidad) { this->cantidad = cantidad; }
	void setPrecio(int precio) { this->precio = precio; }

	void mostrarProducto() {
		cout << "ID: " << idProducto << ", Nombre: " << nombre << ", Tipo: " << tipo
			<< ", Cantidad: " << cantidad << ", Categoria: " << categoria
			<< ", Anio: " << anio << ", Precio: " << precio << endl;
		cout << "Proveedor: ";
		proveedor->mostrarProveedor();
	}


};
