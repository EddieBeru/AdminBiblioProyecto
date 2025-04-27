//
// Created by ugald on 24/4/2025.
//

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
std::string obtenerFechaActual();
//metodo para devolver la fecha de devolucion basado en el tipo de material
std::string calcularFechaDevolucion(Material* material);


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
