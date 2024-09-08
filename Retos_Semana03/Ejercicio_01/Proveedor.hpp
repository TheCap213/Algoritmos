#pragma once
#include <iostream>

using namespace std;

class Proveedor {
private:
	string ruc;
	string razonSocial;
	string categoria;
	string direccion;
	string telefono;
public:
	Proveedor(string ruc, string razonSocial, string categoria, string direccion, string telefono) {
		this->ruc = ruc;
		this->razonSocial = razonSocial;
		this->categoria = categoria;
		this->direccion = direccion;
		this->telefono = telefono;
	}

	string getRuc() { return ruc; }
	string getRazonSocial() { return razonSocial; }
	string getCategortia() { return categoria; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }

	void mostrarProveedor() {
		cout << "RUC: " << ruc << ", Razon Social: " << razonSocial
			<< ", Categoria: " << categoria << ", Direccion: " << direccion
			<< ", Telefono: " << telefono << endl;
	}
};