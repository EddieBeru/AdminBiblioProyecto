/*
* (c) 2025
* EIF204 - Programaci�n 2
* 1er Ciclo - 2025
* NRC 41372 - Grupo 8
* Proyecto 1
*
* 6-0499-0591; Berm�dez Ure�a, Edie
* 4-0264-0704; Arias Med�a, Roy
* 5-0460-0104; Ugalde, Felipe
*
* Version 1.0.0 2025-04-22
*/
#ifndef GESTORPRESTAMOS_H
#define GESTORPRESTAMOS_H

#include <ostream>

#include "../Modelo/Prestamo.h"
#include "../Modelo/Contenedor.h"

class GestorPrestamos {
private:
    Contenedor<Prestamo>* listaPrestamos; //contenedor de prestamos
    public:
GestorPrestamos();
    Contenedor<Prestamo> * get_lista_prestamos() const;
    void agregarPrestamo(Prestamo* prestamo); //agrega un prestamo al contenedor
    bool eliminarPrestamo(int indice);
    friend std::ostream & operator<<(std::ostream &os, const GestorPrestamos &obj) {
        os << "Lista de prestamos:\n";
        os << *obj.listaPrestamos;
        return os;
    }
};


#endif //GESTORPRESTAMOS_H
