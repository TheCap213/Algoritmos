#include "Cliente.h"
#include "Producto.h"
#include "Compras.h"
#include <conio.h>
using namespace std;

int main() {
	Producto p1(101, "Crema Facial", "Cuidado Personal", "MArca A", 50, 20.0);
	Producto p2(102, "Shampoo", "Cuidado Personal", "Marca B", 30, 15.0);

	Cliente c1("12345678", "Juan");

	Compra compra1(1, "2024-09-01", &c1);
	compra1.agregarProducto(&p1);
	compra1.agregarProducto(&p2);

	compra1.mostrarCompra();
	_getch();
	return 0;
}