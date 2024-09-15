#pragma once
#include <iostream>
#include <string>

using namespace std;

class Feedback {
private: 
	string CodigoJugador;
	int Edad;
	string Ciudad;
	string Fecha;
	int MinutosJuego;
	int ScoreRecomendacion;
public:
	Feedback(string codigo, int edadJugador, string ciudadJugador, string fechaRegistro, int minutos, int score) {
		CodigoJugador = codigo;
		Edad = edadJugador;
		Ciudad = ciudadJugador;
		Fecha = fechaRegistro;
		MinutosJuego = minutos;
		ScoreRecomendacion = score;
	}
	~Feedback(){}

	//Getters 

	string getCodigoJugador() { return CodigoJugador; }
	int getEdad() { return Edad; }
	string getCiudad() { return Ciudad; }
	string getFecha() { return Fecha; }
	int getMinutosJuegos() { return MinutosJuego; }
	int getScoreRecomendacion() { return ScoreRecomendacion; }

	void mostrarFeedback() {
		cout << "Codigo: " << CodigoJugador << "\n"
			<< "Edad: " << Edad << "\n"
			<< "Ciudad: " << Ciudad << "\n"
			<< "Fecha: " << Fecha << "\n"
			<< "Minutos: " << MinutosJuego << "\n"
			<< "Score: " << ScoreRecomendacion << endl;
	}
};