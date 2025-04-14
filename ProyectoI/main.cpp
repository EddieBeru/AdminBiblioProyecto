#include <iostream>

#include "Modelo/Libro.h"
#include "Nodo.h"
#include "Contenedor.h"

int main() {

    Libro* p = new Libro(111, 1, "Don Quijote", "", "", "", "", "");
    std::cout << *p << std::endl;
    Libro* p2 = new Libro(21, 1, "El Principito", "", "", "", "", "");
    std::cout << *p2 << std::endl;
    Libro* p3 = new Libro(21, 1, "Diario de Ana Frank", "", "", "", "", "");
    std::cout << *p3 << std::endl;


    std::cout << ((p < p2) ? "p es menor" : "p es mayor o igual") << std::endl;
    std::cout << ((p <= p2) ? "p es menor o igual" : "p es mayor") << std::endl;
    std::cout << ((p > p2) ? "p es mayor" : "p es menor o igual") << std::endl;
    std::cout << ((p >= p2) ? "p es mayor o igual" : "p es menor") << std::endl;
    std::cout << ((p == p2) ? "p es igual a p2" : "p no es igual a p2") << std::endl;
    std::cout << ((p != p2) ? "p no es igual a p2" : "p es igual a p2") << std::endl;

    Contenedor<Libro>* contenedor = new Contenedor<Libro>();
	contenedor->agregarPrincipio(new Nodo<Libro>(*p2));
    contenedor->agregarPrincipio(new Nodo<Libro>(*p));
	contenedor->agregarFinal(new Nodo<Libro>(*p3));
    std::cout << *contenedor << std::endl;
	system("pause");

	contenedor->ordenarAscendente();
	std::cout << *contenedor << std::endl;

    return 0;
}

