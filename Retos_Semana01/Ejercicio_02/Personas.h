#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Persona {
private: 
	string nombre;
	int edad, DNI;
	char sexo;
	float peso, altura;

	char comprobarSexo(char sexo) {
		if (sexo != 'H' && sexo != 'M') {
			return 'H';
		}
		return sexo;
	} 

public:
	Persona() {
		this->nombre = "O";
		this->edad = 0;
		this->DNI = this->generaDNI();
		this->sexo = 'H';
		this->peso = 0.0f;
		this->altura = 0.0f;
	}

	Persona(string nombre, int edad, char sexo) {
		this->nombre = nombre;
		this->edad = edad;
		this->DNI = this->generaDNI();
		this->sexo = sexo;
		this->peso = 0.0f;
		this->altura = 0.0f;
	}

	Persona(string nombre, int edad, char sexo, float peso, float altura) {
		this->nombre = nombre;
		this->edad = edad;
		this->DNI = this->generaDNI();
		this->sexo = sexo;
		this->peso = peso;
		this->altura = altura; 
	}

	int IMC() {
		int pesoIdeal = this->peso / (pow(this->altura, 2));
		if (pesoIdeal < 20) return -1;
		if (pesoIdeal <= 25) return 0;
		return 1;
	}

	bool esMayorDeEdad() {
		return (this->edad >= 18);
	}

	string toString() {
		string aux;
		 aux = "Nombre: " + this->nombre + "\n";
		 aux += "Edad: " + to_string(this->edad) + "\n";
		 aux += "DNI: " + to_string(this->DNI) + "\n";
		 aux += "Sexo: " + string (1, this->sexo) + "\n";
		 aux += "Peso: " + to_string(this->peso) + "\n";
		 aux += "Altura: " + to_string(this->altura) + "\n";
		 return aux;
	}

	int generaDNI() {
		return rand() % (99999999 - 10000000 + 1) + 10000000;
	}

	string pesoIdeal() {
		int imc = this->IMC();
		if (imc == -1) return "Por debajo del peso ideal.";
		if (imc == 0) return "Peso ideal.";
		return "Por encima del peso ideal.";
	}

	~Persona(){}

	// Getters
	string getNombre() {
		return nombre;
	}
	int getEdad() {
		return edad;
	}
	char getSexo() {
		return sexo;
	}
	float getPeso() {
		return peso;
	}
	float getAltura() {
		return altura;
	}

	// Setters
	void setNombre(string nombre) { 
		this->nombre = nombre; 
	}
	void setEdad(int edad) {
		this->edad = edad; 
	}
	void setSexo(char sexo) {
		this->sexo = sexo;
	}
	void setPeso(float peso) {
		this->peso = peso;
	}
	void setAltura(float altura) {
		this->altura = altura;
	}
};