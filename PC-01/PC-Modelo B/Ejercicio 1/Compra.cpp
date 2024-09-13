#include "ListaCompras.hpp"

void Menu() {
    cout << "::::::::::::MENU::::::::::::\n";
    cout << "1.- Agregar nueva compra\n";
    cout << "2.- Listado registro de compras\n";
    cout << "3.- Eliminar compra por codigo\n";
    cout << "4.- Reporte de compras por tipo de cliente\n";
    cout << "5.- Reporte de compras de clientes fidelizados\n";
    cout << "6.- Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {

    Compra* compra;
    ListaCompras* arregloC = new ListaCompras();

    int opc, tipo, cantidad, club, ind;
    string codigo, fecha;
    float total;

    do {
        system("cls");
        Menu();
        cin >> opc;

        switch (opc) {
        case 1: 
            cout << "Ingrese el codigo de cliente: "; cin >> codigo;
            cout << "Ingrese el tipo de cliente (0: nuevo, 1: Frecuente, 2: VIP): "; cin >> tipo;
            cout << "Ingrese la cantidad de productos: "; cin >> cantidad;
            cout << "Ingrese el total: "; cin >> total;
            cout << "Es miembro del club de fidelizacion? (0: No, 1: Si): "; cin >> club;
            cout << "Ingrese la fecha (YYYYMMDD): "; cin >> fecha;

            compra = new Compra(codigo, tipo, cantidad, total, club, fecha);
            arregloC->AgregarCompra(compra);
            break;
        case 2:
            arregloC->MostrarListaCompras();
            system("pause");
            break;
        case 3:
            cout << "Ingrese el codigo de compra a eliminar: ";
            cin >> ind; 
            arregloC->EliminarCompra(ind);
            system("pause");
            break;
        case 4:
            cout << "Ingrese el tipo de cliente a buscar (0, 1, 2): ";
            cin >> tipo;
            arregloC->ReporteTipoCliente(tipo);
            break;
        case 5:
            arregloC->ReporteClientesFidelizados();
            system("pause");
            break;
        case 6: 
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
            system("pause");
            break;
        }
    } while (opc != 6);


    delete arregloC;
    return 0;
}