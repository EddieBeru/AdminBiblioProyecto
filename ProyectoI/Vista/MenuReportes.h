//
// Created by ugald on 24/4/2025.
//

#ifndef MENUREPORTES_H
#define MENUREPORTES_H

#include "../Controlador/GestorMateriales.h"
#include "../Controlador/GestorUsuarios.h"
#include "../Controlador/GestorPrestamos.h"
#include <iostream>
#include <limits>
#include <string>

class MenuReportes {
private:
GestorMateriales* gestorMateriales;
GestorUsuarios* gestorUsuarios;
GestorPrestamos* gestorPrestamos;

//metodos de soporte o auxiliar
void limpiarPantalla();
void pausar();

//metodos para reportes
void reporteInventarioMateriales();
void reporteUsuarios();
void reporteMaterialesEnPrestamo();
void reportePrestamosPorUsuario();
public:
    MenuReportes(GestorMateriales* materiales, GestorUsuarios* usuarios, GestorPrestamos* prestamos);
    ~MenuReportes();

    void mostrarMenu();
};



#endif //MENUREPORTES_H
