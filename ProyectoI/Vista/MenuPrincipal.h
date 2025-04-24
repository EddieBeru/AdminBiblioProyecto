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
#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "../Controlador/GestorMateriales.h"
#include "../Controlador/GestorUsuarios.h"
#include "../Controlador/GestorPrestamos.h"
#include "../Controlador/AdminArchivos.h"
#include <iostream>
#include <string>
#include <limits>

//declaracion adelantada
class MenuMateriales;
class MenuUsuarios;
class MenuPrestamos;
class MenuReportes;

class MenuPrincipal {
private:
  GestorMateriales* gestorMateriales;
  GestorUsuarios* gestorUsuarios;
  GestorPrestamos* gestorPrestamos;

  //submenus de cada uno
MenuMateriales* menuMateriales;
MenuUsuarios* menuUsuarios;
MenuPrestamos* menuPrestamos;
MenuReportes* menuReportes;

//metodos de soporte
void cargarDatos();
void guardarDatos();
void limpiarPantalla();
void pausar();

  public:
    MenuPrincipal();
    ~MenuPrincipal();

    void iniciar();
    void mostrarMenuPrincipal();
};



#endif //MENUPRINCIPAL_H
