#include "ArregloPlatos.h"

short showMenu() {
    short opc;
    do {
        cout << "\tMENU\n";
        cout << "1. Agregar plato\n";
        cout << "2. Modificar datos de un plato\n";
        cout << "3. Eliminar un plato\n";
        cout << "4. Reporte de platos picantes\n";
        cout << "5. Reporte de platos caros\n";
        cout << "6. Mostrar todos los platos\n";
        cout << "7. Salir\n";
        cout << "Ingrese la opcion...";
        cin >> opc;
    } while (opc < 1 || opc > 7); 
    return opc;
}

int main() {
    srand(time(nullptr));
    ArregloPlato* arr = new ArregloPlato();
    while (true) {
        switch (showMenu()) {
        case 1: arr->opAgregarPlato(); break;
        case 2: arr->opModificarPlato(); break;
        case 3: arr->opEliminarPlato(); break;
        case 4: arr->mostrarPlatosPicantes(); break;
        case 5: arr->mostrarPlatosCaros(); break;
        case 6: arr->mostrarDatos(); break; 
        case 7: delete arr; return 0;  
        }
        system("pause>0");
        system("cls");
    }
    delete arr;  
    return 0;
}
