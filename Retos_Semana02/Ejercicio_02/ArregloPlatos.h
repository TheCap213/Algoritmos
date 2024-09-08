#pragma once
#include "Plato.h"

class ArregloPlato {
private:
    Plato** platos;
    int cantidad;
public:
    // Constructor por defecto
    ArregloPlato() {
        platos = nullptr;
        cantidad = 0;
    }
    // Constructor con parámetros
    ~ArregloPlato() {
        for (int i = 0; i < cantidad; i++) {
            delete platos[i];
        }
        delete[] platos;
    }

    // Funciones escenciales 
    void agregarPlato(Plato* pntrPlato) {
        Plato** tmp = new Plato * [cantidad + 1];
        for (int i = 0; i < cantidad; i++) {
            tmp[i] = platos[i];
        }
        tmp[cantidad] = pntrPlato;

        delete[] platos;
        platos = tmp;
        cantidad++;
    }

    void eliminarPlatoEnPosicion(int pos) { 
        if (pos < 0 || pos >= cantidad) {
            cout << "Fuera de rango!\n";
            return;
        }
        delete platos[pos];
        Plato** tmp = new Plato * [cantidad - 1];

        int j = 0;
        for (int i = 0; i < cantidad; i++) {
            if (i == pos) continue;
            tmp[j++] = platos[i];
        }
        delete[] platos;
        platos = tmp;
        cantidad--;
    }

    Plato* getPlato(int pos) {
        if (pos < 0 || pos >= cantidad) {
            cout << "Fuera de rango!\n";
            return nullptr;
        }
        return platos[pos];
    }

    void mostrarDatos() {
        cout << "-->Todos los platos son los siguientes:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "Plato n" << i + 1 << endl;
            platos[i]->mostrarDatos();
            cout << endl;
        }
    }

    void mostrarPlatosPicantes() {
        cout << "-->Los platos picantes son los siguientes:\n";
        for (int i = 0; i < cantidad; i++) {
            if (platos[i]->getEsPicante()) {
                cout << "Plato n" << i + 1 << endl;
                platos[i]->mostrarDatos();
                cout << endl;
            }
        }
    }

    void mostrarPlatosCaros() {
        cout << "-->Los platos caros son los siguientes:\n";
        for (int i = 0; i < cantidad; i++) {
            if (platos[i]->getPrecioPromedio() > 100) {
                cout << "Plato n" << i + 1 << endl;
                platos[i]->mostrarDatos();
                cout << endl;
            }
        }
    }

    Plato* crearPlato() {
        string nombrePlato;
        bool esFrio, esPicante;
        float cantidadCalorias, precioPromedio;
        cout << "Nombre del Plato: "; cin >> nombrePlato;
        cout << "Es Frio (1: V, 0: F): "; cin >> esFrio;
        cout << "Es Picante (1: V, 0: F): "; cin >> esPicante;  
        cout << "Cantidad de calorias: "; cin >> cantidadCalorias;
        cout << "Precio Promedio: "; cin >> precioPromedio;
        return new Plato(nombrePlato, esFrio, esPicante, cantidadCalorias, precioPromedio);
    }

    void opAgregarPlato() {
        short opc;
        do {
            cout << "\n1. Agregar plato default\n";
            cout << "2. Ingresar datos manualmente\n";
            cin >> opc;
        } while (opc < 1 || opc > 2);

        switch (opc) {
        case 1:
            agregarPlato(new Plato());  
            cout << "Plato por defecto agregado.\n";  
            break;
        case 2:
            agregarPlato(crearPlato());
            cout << "Plato agregado con datos ingresados manualmente.\n"; 
            break;
        }
    }

    void opModificarPlato() {
        int pos;
        cout << "Ingrese numero de plato a modificar: ";
        cin >> pos;
        if (pos < 0 || pos >= cantidad) {
            cout << "Posicion fuera de rango!" << endl;
            return;
        }
        platos[pos]->mostrarDatos();
        cout << "\nIngrese nuevos valores: ";
        delete platos[pos];  
        platos[pos] = crearPlato();
    }

    void opEliminarPlato() {
        int pos;
        cout << "Ingrese posicion del plato a eliminar: "; 
        cin >> pos;
        eliminarPlatoEnPosicion(pos);  
    }

};
