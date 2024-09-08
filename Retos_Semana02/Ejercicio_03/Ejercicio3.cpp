#include "ArregloContactos.h"

short showMenu() {
    short opc;
    do {
        cout << "\tMENU\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Modificar datos de un contacto\n";
        cout << "3. Eliminar un contacto\n";
        cout << "4. Reporte de contactos que son varones\n";
        cout << "5. Reporte de contactos con Facebook o WhatsApp\n";
        cout << "6. Mostrar todos los contactos\n";
        cout << "7. Salir\n";
        cout << "Ingrese la opcion...";
        cin >> opc;
    } while (opc < 1 || opc > 7); 
    return opc;
}

int main() {
    srand(time(nullptr));
    ArregloContactos* arr = new ArregloContactos();
    while (true) {
        switch (showMenu()) {
        case 1: arr->opAgregarContacto(); break;
        case 2: arr->opModificarContacto(); break;
        case 3: arr->opEliminarContacto(); break;
        case 4: arr->mostrarContactoVaron(); break;
        case 5: arr->mostrarContactosRedSocial(); break;
        case 6: arr->mostrarDatos(); break;
        case 7: delete arr; 
        return 0; 
        }
        system("pause>0");
        system("cls");
    }
    delete arr;  
    return 0;
}
