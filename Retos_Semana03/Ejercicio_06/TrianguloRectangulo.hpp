#pragma once
#include "Herramienta.h"
using namespace std;
using namespace chrono;

class TrianguloRectangulo {
private:
    int lado1;
    int lado2;
    char caracter;
public:
    TrianguloRectangulo(int lado1, int lado2, char caracter) {
        if (lado1 < 5 || lado1 > 100 || lado2 < 5 || lado2 > 100) {
            throw invalid_argument("Los lados deben estar entre 5 y 100.");
        }
        this->lado1 = lado1;
        this->lado2 = lado2;
        this->caracter = caracter;
    }

    void dibujar() {
        system("cls"); 

        for (int i = 0; i < lado1; i++) {
            SetCursorPosition(10, 10 - i);  // Lado vertical
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));
        }

        for (int i = 0; i < lado2; i++) {
            SetCursorPosition(10 + i * 2, 10);  // Lado horizontal
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));
        }

        for (int i = 0; i < min(lado1, lado2); i++) {
            SetCursorPosition(10 + i * 2, 10 - i);  // Lado diagonal
            cout << caracter;
            this_thread::sleep_for(milliseconds(100));
        }
    }
};
