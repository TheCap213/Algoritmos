#include "TrianguloEquilatero.hpp"
#include "TrianguloRectangulo.hpp"
#include <conio.h>

void mostrarMenu() {
    cout << "\tMENU" << endl;
    cout << "1. Triangulo Equilatero Horario\n";
    cout << "2. Triangulo Rectangulo Horario\n";
    cout << "Ingrese la opcion: ";
}

int main() {
    int opc;
    do {
        system("cls");
        mostrarMenu();
        cin >> opc;

        switch (opc) {
        case 1: {
            int lado;
            char caracter;
            cout << "Ingrese el lado (5-100): ";
            cin >> lado;
            cout << "Ingrese el caracter: ";
            cin >> caracter;

            try {
                TrianguloEquilatero triangulo(lado, caracter);
                triangulo.dibujar();
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
            }

            break;
        }

        case 2: {
            int lado1, lado2;
            char caracter;
            cout << "Ingrese el lado1 (5-100): ";
            cin >> lado1;
            cout << "Ingrese el lado2 (5-100): ";
            cin >> lado2;
            cout << "Ingrese el caracter: ";
            cin >> caracter;

            try {
                TrianguloRectangulo triangulo(lado1, lado2, caracter);
                triangulo.dibujar();
            }
            catch (invalid_argument& e) {
                cout << e.what() << endl;
            }

            break;
        }

        case 3:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
        }
        _getch();  
        system("pause"); 
    } while (opc != 3);

    return 0;
}
