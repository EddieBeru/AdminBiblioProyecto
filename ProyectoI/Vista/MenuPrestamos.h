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
#ifndef MENUPRESTAMOS_H
#define MENUPRESTAMOS_H

#include "../Controlador/GestorPrestamos.h"
#include "../Controlador/GestorMateriales.h"
#include "../Controlador/GestorUsuarios.h"
#include <iostream>
#include <limits>
#include <string>
#include <ctime>

class MenuPrestamos {
private:
  GestorPrestamos* gestorPrestamos;
  GestorMateriales* gestorMateriales;
  GestorUsuarios* gestorUsuarios;

  //metodos de soporte o auxiliar
  void limpiarPantalla();
  void pausar();
  int solicitarEntero(const std::string& mensaje);
  std::string solicitarTexto(const std::string& mensaje);

//hacer algo para las fechas


  //metodos de operacion
  void registrarPrestamo();
  void registrarDevolucion();
  void mostrarPrestamos();
public:
	MenuPrestamos(GestorPrestamos* prestamos, GestorMateriales* materiales, GestorUsuarios* usuarios);
	~MenuPrestamos();

	void mostrarMenu();
};



#endif //MENUPRESTAMOS_H
