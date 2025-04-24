//
// Created by ugald on 24/4/2025.
//

#include "MenuPrincipal.h"
#include "MenuMateriales.h"
#include "MenuUsuarios.h"
#include "MenuPrestamos.h"
#include "MenuReportes.h"
#include <iostream>
#include <cstdlib>


MenuPrincipal::MenuPrincipal() {
  gestorMateriales=new GestorMateriales();
  gestorUsuarios=new GestorUsuarios();
  gestorPrestamos=new GestorPrestamos();

//me falta seguir aca

}

MenuPrincipal::~MenuPrincipal() {
  //falta desarrollar
}

void MenuPrincipal::cargarDatos(){
try{
  AdminArchivos::cargarMateriales(*gestorMateriales);
  AdminArchivos::cargarUsuarios(*gestorUsuarios);
}catch(const std::exception& e){
  std::cerr<<"Error al cargar datos: "<<e.what()<<std::endl;
}
}

void MenuPrincipal::guardarDatos(){
  try{
    AdminArchivos::guardarMateriales(*gestorMateriales);
    AdminArchivos::guardarUsuarios(*gestorUsuarios);
  }catch(const std::exception& e){
    std::cerr<<"Error al guardar datos: "<<e.what()<<std::endl;
  }
}

void MenuPrincipal::limpiarPantalla(){
  std::system("cls");
}

void MenuPrincipal::pausar(){
  std::cout<<"Presione Enter para continuar...."<<std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}