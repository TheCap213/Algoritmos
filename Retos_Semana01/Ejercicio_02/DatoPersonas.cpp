#include "Personas.h"
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
	string nombre;
	int edad, DNI;
	char sexo;
	float peso, altura;

    cout << "---------------------" << endl;
    cout << "- INGRESE SUS DATOS -" << endl;
    cout << "---------------------" << endl;
    cout << "Nombre: "; cin >> nombre;
    cout << "Edad: "; cin >> edad;
    cout << "Sexo (H para hombre, M para mujer): "; cin >> sexo;
    cout << "Peso (kg): "; cin >> peso;
    cout << "Altura (m): "; cin >> altura;
    cout << "\n";

    Persona* persona1 = new Persona(nombre, edad, sexo, peso, altura);
    Persona* persona2 = new Persona(nombre, edad, sexo);
    Persona* persona3 = new Persona();

    //Mostrar info de cada persona segun nos lo indica el problema
    cout << "----- PERSONA 1 -----" << endl;
    cout << persona1->toString() << endl;
     
    cout << "----- PERSONA 2 -----" << endl;
    cout << persona2->toString() << endl;

    cout << "----- PERSONA 3 -----" << endl;
    cout << persona3->toString() << endl;

    //Verificar y mostrar el peso idea con la mayoria de edad
    cout << "----- PERSONA 1 -----" << endl;
    cout << "Peso Ideal: " << persona1->pesoIdeal() << endl;
    cout << "Es mayor de edad: " << (persona1->esMayorDeEdad() ? "SI" : "NO") << endl;

    cout << "----- PERSONA 2 -----" << endl;
    cout << "Peso Ideal: " << persona2->pesoIdeal() << endl;
    cout << "Es mayor de edad: " << (persona2->esMayorDeEdad() ? "SI" : "NO") << endl;

    cout << "----- PERSONA 3 -----" << endl;
    cout << "Peso Ideal: " << persona3->pesoIdeal() << endl;
    cout << "Es mayor de edad: " << (persona3->esMayorDeEdad() ? "SI" : "NO") << endl;

    delete persona1;
    delete persona2;
    delete persona3;

    _getch();
    system("pause");
    return 0;
}