#pragma once
#include <iostream>
#include <string>

using namespace std;

class Compra {
private:
	string codCliente;
	int tipoCliente;
	int cantProductos;
	double total;
	bool clubFide;
	string fecha;
public:
	Compra(string codCliente, int tipoCliente, int cantProductos, double total, bool clubFide, string fecha) {
		this->codCliente = codCliente;
		this->tipoCliente = tipoCliente;
		this->cantProductos = cantProductos;
		this->total = total;
		this->clubFide = clubFide;
		this->fecha = fecha;
	}

	string getCodigoCliente() { return codCliente; }
	int getTipoCliente() { return tipoCliente; }
	int getCantidadProductos() { return cantProductos; }
	double getTotal() { return total; }
	bool getClubFidelizacion() { return clubFide; }
	string getFecha() { return fecha; }

	void setCodigoCliente(string codigo) { codCliente = codigo; }
	void setCantidadProductos(int cantidad) { cantProductos = cantidad; }
	void setTotal(int t) { total = t; }
	void setClubFidelizacion(int club) { clubFide = club; }
	void setFecha(string f) { fecha = f; }

	void MostrarCompra() {
		cout << fecha << "\t" << codCliente << "\t" << tipoCliente << "\t"
			<< cantProductos << "\t" << total << "\t" << clubFide << endl;
	}

};