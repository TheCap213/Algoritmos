#pragma once 
#include "VectorEclipses.h"

class Controladora {
private: 
	VectorEclipses* vecEclipses;
public:
	Controladora();
	~Controladora();
	void RegistroDatos();
	void ModificarDatos();
	void EliminarDatos();
	void ReporteTodosEclipses();
	void ReporteEclipsesEuropa();
	void ReporteEclipsesSismos();
	void ReporteEclipsesNoche();
	bool existenEclipses();
};

Controladora::Controladora() {
	vecEclipses = new VectorEclipses();
}

Controladora::~Controladora() {
	delete vecEclipses;
}

void Controladora::RegistroDatos() {
	string tipo, fecha, visibilidad;
	int hora;
	char sismos, lluvias;
	cout << "Ingrese Tipo de Eclipse: ";
	cin.ignore();
	getline(cin, tipo);
	cout << "Ingrese Fecha: ";
	cin.ignore();
	getline(cin, fecha);
	do {
		cout << "Ingrese Hora: "; cin >> hora;
	} while (hora < 100 || hora > 2400);
	do {
		cout << "Hubo Sismos?: "; cin >> sismos;
	} while (sismos != 'S' && sismos != 'N');
	do {
		cout << "Hubo lluvias?: "; cin >> lluvias;
	} while (lluvias != 'S' && lluvias != 'N');
	
	cout << "Continente que tiene mayor visbilidad: "; 
	cin.ignore();
	getline(cin, visibilidad);
	Eclipse* eclipse = new Eclipse(tipo, fecha, hora, sismos, lluvias, visibilidad);
	vecEclipses->RegistrarEclipse(eclipse);
}

void Controladora::ModificarDatos() {
	string tipo, fecha, visbilidad;
	int indice, hora, opcion;
	char sismos, lluvias;
	cout << "Ingrese el indice del elcipse a modificar: "; cin >> indice;
	if (indice < 0 || indice >= vecEclipses->getNumEclipses()) {
		cout << endl << "indice fuera de rango!" << endl;
		return;
	}
	Eclipse* eclipse = vecEclipses->obtenerDatosEclipse(indice);

	do {
		cout << "Seleccione el atributo a modificar:" << endl;
		cout << "1. Tipo de Eclipse" << endl;
		cout << "2. Fecha" << endl;
		cout << "3. Hora" << endl;
		cout << "4. Sismos" << endl;
		cout << "5. Lluvias" << endl;
		cout << "6. Visibilidad" << endl;
		cout << "\nIngrese Opcion: "; cin >> opcion;
		system("cls");

		switch (opcion) {
		case 1: 
			system("cls");
			cout << "Ingrese el nuevo tipo de eclipse: ";
			cin.ignore();
			getline(cin, tipo);
			eclipse->setTipo(tipo);
			system("pause>0");
			break;
		case 2:
			system("cls");
			cout << "Ingrese la nueva fecha: ";
			cin.ignore();
			getline(cin, fecha);
			eclipse->setFecha(fecha);
			system("pause>0");
			break;
		case 3:
			system("cls");
			do {
				cout << "Ingrese la nueva hora: "; cin >> hora;
			} while (hora < 100 || hora > 2400);
			eclipse->setHora(hora); 
			break;
		case 4:
			system("cls");
			do {
				cout << "Hubo sismos?: "; cin >> sismos;
			} while (sismos != 'S' && sismos != 'N');
			eclipse->setSismos(sismos); 
			break;
		case 5:
			system("cls");
			do {
				cout << "Hubo lluvias?: "; cin >> lluvias;
			} while (lluvias != 'S' && lluvias != 'N');
			eclipse->setLluvias(lluvias);
			break;
		case 6:
			system("cls");
			cout << "Ingrese el nuevo continente con mayor visibilidad: ";
			cin.ignore();
			getline(cin, visbilidad);
			eclipse->setVisibilidad(visbilidad);
			system("pause>0");
			break;
		case 0:
			break;
		}
		system("cls");
	} while (opcion != 0);
	cout << "SE MODIFICO CON EXITO LOS DATOS DEL ECLIPSE!!!" << endl;
}

void Controladora::EliminarDatos() {
	int indice;
	cout << "Ingrese el indice del eclipse a eliminar: "; cin >> indice;
	if (indice < 0 || indice >= vecEclipses->getNumEclipses()) {
		cout << endl << "Indice fuera de rango!" << endl;
		return;
	}
	vecEclipses->EliminarEclipse(indice);
	cout << "\nSE ELIMINO CON EXITO LOS DATOS DEL ECLIPSE!!!" << endl;
}

void Controladora::ReporteTodosEclipses(){
	cout << "\t\tREPORTE DE TODOS LOS ECLIPSES\n\n"; 
	for (int i = 0; i < vecEclipses->getNumEclipses(); i++) {
		vecEclipses->obtenerDatosEclipse(i)->MostrarEclipse();
		cout << endl;
	}
}
void Controladora::ReporteEclipsesEuropa() {
	bool found = false;
	for (int i = 0; i < vecEclipses->getNumEclipses(); i++) {
		if (vecEclipses->obtenerDatosEclipse(i)->getVisibilidad() == "Europa") {
			if (!found) {
				cout << "\t\tECLIPSES VISIBLES EN EUROPA\n\n";
				found = true;
			}
			vecEclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found) {
		cout << "NO HAY ECLIPSES QUE SON VISIBLES EN EUROPA" << endl;
	}
}

void Controladora::ReporteEclipsesSismos() {
	bool found = false;
	for (int i = 0; i < vecEclipses->getNumEclipses(); i++) {
		if (vecEclipses->obtenerDatosEclipse(i)->getSismos() == 'S') {
			if (!found) {
				cout << "\t\tECLIPSES CON SISMOS\n\n";
				found = true;
			}
			vecEclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found) {
		cout << "NO HAY ECLIPSES QUE TENGAN SISMOS ASOCIADOS" << endl;
	}
}

void Controladora::ReporteEclipsesNoche() {
	bool found = false;
	for (int i = 0; i < vecEclipses->getNumEclipses(); i++) {
		int hora = vecEclipses->obtenerDatosEclipse(i)->getHora();
		if ((hora >= 100 || hora < 600) && vecEclipses->obtenerDatosEclipse(i)->getTipo() == "Lunar") {
			if (!found) {
				cout << "\t\tECLIPSES QUE SE PRODUJERON DE NOCHE\n\n";
				found = true;
			}
			vecEclipses->obtenerDatosEclipse(i)->MostrarEclipse();
			cout << endl;
		}
	}
	if (!found) {
		cout << "NO HAY ECLIPSES QUE SE PRODUJERON EN LA NOCHE" << endl;
	}
}

bool Controladora::existenEclipses() {
	return vecEclipses->getNumEclipses() > 0;
}