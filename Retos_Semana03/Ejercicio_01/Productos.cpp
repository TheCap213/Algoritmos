#include "Producto.hpp"
#include <iostream>
#include <conio.h>
using namespace std;

void mostrarMenu() {
    cout << "\tMENU" << endl;
    cout << "1. Insertar producto" << endl;
    cout << "2. Insertar proveedor" << endl;
    cout << "3. Modificar Producto" << endl;
    cout << "4. Eliminar productos vencidos" << endl;
    cout << "5. Reportes" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Producto* productos[100]; 
    Proveedor* proveedores[50]; 
    int numProductos = 0;
    int numProveedores = 0;

    int opc;
    do {
        system("cls");
        mostrarMenu();
        cin >> opc;

        switch (opc) {
        case 1: {
            string nombre, tipo;
            int idProducto, cantidad, anio;
            char categoria;
            double precio;
            string rucProveedor;

            cout << "Ingrese el ID del producto: ";
            cin >> idProducto;
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el tipo de producto (polvo o liquido): ";
            cin >> tipo;
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;
            cout << "Ingrese la categoria (A, B, C): ";
            cin >> categoria;
            cout << "Ingrese el año de fabricación: ";
            cin >> anio;
            cout << "Ingrese el precio: ";
            cin >> precio;
            cout << "Ingrese el RUC del proveedor: ";
            cin >> rucProveedor;

            Proveedor* proveedor = nullptr;
            for (int i = 0; i < numProveedores; i++) {
                if (proveedores[i]->getRuc() == rucProveedor) {
                    proveedor = proveedores[i];
                    break;
                }
            }

            if (proveedor == nullptr) {
                cout << "Proveedor no encontrado." << endl;
                _getch();
                break;
            }

            productos[numProductos++] = new Producto(idProducto, nombre, tipo, cantidad, categoria, anio, precio, proveedor);
            cout << "Producto insertado correctamente." << endl;
            break;
        }

        case 2: {
            string ruc, razonSocial, categoria, direccion, telefono;
            cout << "Ingrese el RUC del proveedor: ";
            cin >> ruc;
            cout << "Ingrese la razon social: ";
            cin >> razonSocial;
            cout << "Ingrese la categoria: ";
            cin >> categoria;
            cout << "Ingrese la direccion: ";
            cin >> direccion;
            cout << "Ingrese el telefono: ";
            cin >> telefono;

            proveedores[numProveedores++] = new Proveedor(ruc, razonSocial, categoria, direccion, telefono);
            cout << "Proveedor insertado correctamente." << endl;
            break;
        }

        case 6:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
        }
        _getch(); 

    } while (opc != 6);

    return 0;
}
