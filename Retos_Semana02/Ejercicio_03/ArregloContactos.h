#pragma once
#include "Contacto.h"

class ArregloContactos {
private:
    Contacto** contactos;
    int cantidad;

public:
    // Constructor
    ArregloContactos() {
        contactos = nullptr;
        cantidad = 0;
    }

    // Destructor
    ~ArregloContactos() {
        for (int i = 0; i < cantidad; i++) {
            delete contactos[i];
        }
        delete[] contactos;
    }

    // Agregar un nuevo contacto
    void agregarContacto(Contacto* contacto) {
        Contacto** tmp = new Contacto * [cantidad + 1];
        for (int i = 0; i < cantidad; i++) {
            tmp[i] = contactos[i];
        }
        tmp[cantidad] = contacto;

        delete[] contactos;
        contactos = tmp;
        cantidad++;
    }

    // Eliminar un contacto por posición
    void eliminarContactoEnPosicion(int pos) {
        if (pos < 0 || pos >= cantidad) {
            cout << "Fuera de rango!\n";
            return;
        }
        delete contactos[pos];
        Contacto** tmp = new Contacto * [cantidad - 1];

        int j = 0;
        for (int i = 0; i < cantidad; i++) {
            if (i == pos) continue;
            tmp[j++] = contactos[i];
        }
        delete[] contactos;
        contactos = tmp;
        cantidad--;
    }

    // Mostrar todos los contactos
    void mostrarDatos() {
        cout << "-->Todos los contactos son los siguientes:\n";
        for (int i = 0; i < cantidad; i++) {
            cout << "Contacto n" << i + 1 << endl;
            contactos[i]->mostrarDatos();
            cout << endl;
        }
    }

    // Mostrar contactos que son varones
    void mostrarContactoVaron() {
        cout << "-->Los contactos que son varones son:\n";
        for (int i = 0; i < cantidad; i++) {
            if (contactos[i]->getSexo() == "Masculino" || contactos[i]->getSexo() == "Varon") {
                cout << "Contacto n" << i + 1 << endl;
                contactos[i]->mostrarDatos();
                cout << endl;
            }
        }
    }

    // Mostrar contactos que tienen Facebook o WhatsApp
    void mostrarContactosRedSocial() {
        cout << "-->Los contactos que tienen Facebook o WhatsApp son:\n";
        for (int i = 0; i < cantidad; i++) {
            string redSocial = contactos[i]->getRedSocial();
            if (redSocial == "Facebook" || redSocial == "WhatsApp") {
                cout << "Contacto n" << i + 1 << endl;
                contactos[i]->mostrarDatos();
                cout << endl;
            }
        }
    }

    // Crear un nuevo contacto ingresando datos manualmente
    Contacto* crearContacto() {
        string nombre, sexo, facultad, email, redSocial;
        long long telefono;
        int dia, mes, anio;

        cout << "Nombre del Contacto: "; cin >> nombre;
        cout << "Sexo (Masculino/Femenino): "; cin >> sexo;
        cout << "Facultad: "; cin >> facultad;
        cout << "Email: "; cin >> email;
        cout << "Red Social (Facebook, WhatsApp, etc.): "; cin >> redSocial;
        cout << "Telefono: "; cin >> telefono;
        cout << "Fecha de nacimiento:\n";
        cout << "  Dia: "; cin >> dia;
        cout << "  Mes: "; cin >> mes;
        cout << "  Anio: "; cin >> anio;

        Fecha* nacimiento = new Fecha(dia, mes, anio);
        return new Contacto(nombre, sexo, facultad, email, redSocial, nacimiento, telefono);
    }

    // Agregar contacto a través de opciones
    void opAgregarContacto() {
        short opc;
        do {
            cout << "1. Agregar contacto por defecto\n";
            cout << "2. Ingresar datos manualmente\n";
            cin >> opc;
        } while (opc < 1 || opc > 2);
        switch (opc) {
        case 1:
            agregarContacto(new Contacto());
            cout << "Contacto por defecto agregado exitosamente." << endl;
            break;
        case 2:
            agregarContacto(crearContacto());
            cout << "Contacto agregado exitosamente." << endl;
            break;
        default:
            break;
        }
    }

    // Modificar datos de un contacto
    void opModificarContacto() {
        int pos;
        cout << "Ingrese numero de contacto a modificar: ";
        cin >> pos;
        if (pos < 0 || pos >= cantidad) {
            cout << "Posicion fuera de rango!" << endl;
            return;
        }
        contactos[pos]->mostrarDatos();
        cout << "\nIngrese nuevos valores: ";
        delete contactos[pos];  
        contactos[pos] = crearContacto();
    }

    // Eliminar contacto
    void opEliminarContacto() {
        int pos;
        cout << "Ingrese posicion del contacto a eliminar: ";
        cin >> pos;
        eliminarContactoEnPosicion(pos);
    }
};
