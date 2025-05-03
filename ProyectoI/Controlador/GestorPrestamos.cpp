/*
* (c) 2025
* EIF204 - Programación 2
* 1er Ciclo - 2025
* NRC 41372 - Grupo 8
* Proyecto 1
*
* 6-0499-0591; Bermúdez Ureña, Edie
* 4-0264-0704; Arias Medía, Roy
* 5-0460-0104; Ugalde, Felipe
*
* Version 1.0.0 2025-04-22
*/
#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos() {
    listaPrestamos=new Contenedor<Prestamo>();
}



void GestorPrestamos::agregarPrestamo(Prestamo *prestamo) {
    listaPrestamos->agregarFinal(new Nodo<Prestamo>(prestamo));
}

Contenedor<Prestamo> *GestorPrestamos::get_lista_prestamos() const {
    return listaPrestamos;
}

bool GestorPrestamos::eliminarPrestamo(int indice) {

}