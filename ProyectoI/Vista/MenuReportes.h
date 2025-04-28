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
int solicitarEntero(const std::string& mensaje);
std::string solicitarTexto(const std::string& mensaje);


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
