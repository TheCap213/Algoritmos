#pragma once
#include <iostream>
#include <string>

using namespace std;

class Plato {
private:
    string nombrePlato;
    bool esFrio;
    bool esPicante;
    float cantidadCalorias;
    float precioPromedio;

public:
    // Constructor por defecto
    Plato() {
        nombrePlato = "Plato Default";  
        esFrio = false;                 
        esPicante = false;              
        cantidadCalorias = 0.0;         
        precioPromedio = 0.0;           
    }

    // Constructor con parámetros
    Plato(string nombre, bool frio, bool picante, float calorias, float precio) {
        nombrePlato = nombre;
        esFrio = frio;
        esPicante = picante;
        cantidadCalorias = calorias;
        precioPromedio = precio;
    }

    void mostrarDatos() {
        cout << "Nombre del Plato: " << nombrePlato << endl;
        cout << "Es frio: " << (esFrio ? "Si" : "No") << endl;
        cout << "Es picante: " << (esPicante ? "Si" : "No") << endl;
        cout << "Calorias: " << cantidadCalorias << endl;
        cout << "Precio promedio: " << precioPromedio << endl;
    }

    string getNombre() { return nombrePlato; }
    bool getEsFrio() { return esFrio; }
    bool getEsPicante() { return esPicante; }
    float getCantidadCalorias() { return cantidadCalorias; }
    float getPrecioPromedio() { return precioPromedio; }
};
