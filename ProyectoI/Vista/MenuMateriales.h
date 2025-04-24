//
// Created by ugald on 24/4/2025.
//

#ifndef MENUMATERIALES_H
#define MENUMATERIALES_H

#include "../Controlador/GestorMateriales.h"
#include <iostream>
#include <limits>
#include <string>

class MenuMateriales {
private:
  GestorMateriales* gestor;
  //metodos de soporte o auxiliar
  void limpiarPantalla();
  void pausar();
  int solicitarEntero(const std::string& mensaje);
  std::string solicitarTexto(const std::string& mensaje);

  //Metodos de operacion segun menu
  //metodos de agregar
void agregarMaterial();
void agregarLibro();
void agregarRevista();
void agregarDigitalEnLinea();
void agregarDigitalFisico();
//metodos de modificar

//metodos mostrar

  public:
    MenuMateriales(GestorMateriales *gestorMateriales);
    ~MenuMateriales();
    void mostrarMenu();
};



#endif //MENUMATERIALES_H
