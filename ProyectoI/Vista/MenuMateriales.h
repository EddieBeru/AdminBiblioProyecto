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
void modificarMaterial();
void modificarLibro(int numClasificacion);
void modificarRevista(int numClasificacion);
void modificarDigitalEnLinea(int numClasificacion);
void modificarDigitalFisico(int numClasificacion);

//metodos mostrar
void mostrarMateriales();
void buscarMaterial();

  public:
    MenuMateriales(GestorMateriales *gestorMateriales);
    ~MenuMateriales();
    void mostrarMenu();
};



#endif //MENUMATERIALES_H
