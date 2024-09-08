#pragma once
#include "Fecha.h"

using namespace std;

class Contacto {
private:
    string nombre;
    string sexo;
    string facultad;
    string email;
    string redSocial;
    Fecha* nacimiento;
    long long telefono;

public:
    // Constructor por defecto
    Contacto() {
        this->nombre = "Contacto Default";
        this->sexo = "Desconocido";
        this->facultad = "Sin Facultad";
        this->email = "default@example.com";
        this->redSocial = "Ninguna";
        this->nacimiento = new Fecha();
        telefono = rand() % (999999999 - 900000000 + 1) + 900000000;
    }

    // Constructor con parámetros
    Contacto(string nombre, string sexo, string facultad, string email, string redSocial, Fecha* nacimiento, long long telefono) {
        this->nombre = nombre;
        this->sexo = sexo;
        this->facultad = facultad;
        this->email = email;
        this->redSocial = redSocial;
        this->nacimiento = nacimiento;
        this->telefono = telefono;
    }

    // Destructor
    ~Contacto() {
        delete nacimiento;
    }

    // Mostrar datos
    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Sexo: " << sexo << endl;
        cout << "Facultad: " << facultad << endl;
        cout << "Email: " << email << endl;
        cout << "Red Social: " << redSocial << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Fecha de nacimiento: ";
        nacimiento->mostrarFecha();
    }

    // Getters
    string getNombre() { return nombre; }
    string getSexo() { return sexo; }
    string getFacultad() { return facultad; }
    string getEmail() { return email; }
    string getRedSocial() { return redSocial; }
    Fecha* getNacimiento() { return nacimiento; }
    long long getTelefono() { return telefono; }

    // Setters
    void setNombre(string nombre) { 
        this->nombre = nombre; 
    }
    void setSexo(string sexo) { 
        this->sexo = sexo; 
    }
    void setFacultad(string facultad) { 
        this->facultad = facultad;
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setRedSocial(string redSocial) {
        this->redSocial = redSocial;
    }
    void setNacimiento(Fecha* nacimiento) {
        delete this->nacimiento;
        this->nacimiento = nacimiento;
    }
    void setTelefono(long long telefono) { 
        this->telefono = telefono; 
    }
};
