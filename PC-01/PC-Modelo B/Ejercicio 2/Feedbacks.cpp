#include "ListaFeedback.h"
#include <conio.h>

using namespace std;

int Menu() {
	int opc; 
	do {
        cout << "::::::::::::MENU::::::::::::\n";
        cout << "1.- Agregar registro de feedback\n";
        cout << "2.- Listar registro de feedback\n";
        cout << "3.- Eliminar registro de feedback\n";
        cout << "4.- Reporte de feedback de ciudad LIMA\n";
        cout << "5.- Reporte de jugador con mayor minutos jugados\n";
        cout << "6.- Reporte de feedback correspondiente a Agosto 2024\n";
        cout << "7.- Reporte de feedback con Score Recomendacion menores a 5\n";
        cout << "8.- Salir\n";
        cout << "Seleccione una opcion: "; cin >> opc;
    } while (opc < 1 || opc > 8);
    return opc; 
}

void PresionaContinuar() {
    cout << endl << "Presiona una tecla para continuar...";
    _getch();
}

int main() {
    Feedback* feedback;
    ListaFeedbacks* arregloF = new ListaFeedbacks();

    int opc;
    int ind;
    string CodigoJugador;
    int Edad;
    string Ciudad;
    string Fecha;
    int MinutosJuego;
    int ScoreRecomendacion;

    while (true) {
        system("cls");
        opc = Menu();

        switch (opc) {
        case 1:
            cout << endl << "Ingrese los datos para el Feedback" << endl;
            cout << "Codigo de Jugador: "; cin >> CodigoJugador;
            cout << "Edad: "; cin >> Edad;
            cout << "Ciudad: "; cin >> Ciudad;
            cout << "Fecha: "; cin >> Fecha;
            cout << "Minutos de Juego: "; cin >> MinutosJuego;
            cout << "Score: "; cin >> ScoreRecomendacion;

            feedback = new Feedback(CodigoJugador, Edad, Ciudad, Fecha, MinutosJuego, ScoreRecomendacion);
            arregloF->AgregarFeedback(feedback);
            PresionaContinuar();
            break;
            
        case 2:
            arregloF->MostrarListaFeedbacks();
            PresionaContinuar();
            break;

        case 3:
            cout << "Ingrese el codigo del Feedback a eliminar: "; 
            cin >> ind;
            arregloF->EliminarFeedback(ind);
            PresionaContinuar();
            break;

        case 4:
            arregloF->ReporteCiudadLima();
            system("pause");
            PresionaContinuar();
            break;

        case 5:
            arregloF->ReporteMayorMinutos();
            PresionaContinuar();
            break;

        case 6:
            arregloF->ReporteAgosto2024();
            PresionaContinuar();
            break;

        case 7: 
            arregloF->ReportesScoreMenorCinco();
            PresionaContinuar();
            break;

        case 8: 
            cout << "Saliendo....." << endl;
            break;
            
        default:
            cout << "Opcion no valida.\n";
            system("pause");
            break;
        }
    } while (opc != 6);

    delete arregloF;
    return 0;
}