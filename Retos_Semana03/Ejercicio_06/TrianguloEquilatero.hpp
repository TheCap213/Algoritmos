#pragma once
#include "Herramienta.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

class TrianguloEquilatero {
private:
    int lado;
    char caracter;
public:
    TrianguloEquilatero(int lado, char caracter) {
        if (lado < 5 || lado > 100) {
            throw invalid_argument("El lado debe estar entre 5 y 100");
        }
        this->lado = lado;
        this->caracter = caracter;
    }

    void dibujar() {
        system("cls"); 
        for (int i = 0; i < lado; i++) {
            SetCursorPosition(10 + i * 2, 10);  // Línea base
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));  // Pausa de 100 ms
        }

        for (int i = 0; i < lado; i++) {
            SetCursorPosition(10 + i * 2, 10 - i);  // Lado izquierdo
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));
        }

        for (int i = 0; i < lado; i++) {
            SetCursorPosition(10 + lado * 2, 10 - i);  // Lado derecho
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));
        }
    }
};
