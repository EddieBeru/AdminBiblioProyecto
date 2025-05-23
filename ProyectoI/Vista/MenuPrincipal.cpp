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
menuMateriales=new MenuMateriales(gestorMateriales);
menuUsuarios=new MenuUsuarios(gestorUsuarios);
menuPrestamos=new MenuPrestamos(gestorPrestamos, gestorMateriales, gestorUsuarios);
menuReportes=new MenuReportes(gestorMateriales, gestorUsuarios, gestorPrestamos);

  //cargar
  cargarDatos();
}

MenuPrincipal::~MenuPrincipal() {
    //delete todo
    delete gestorMateriales;
    delete gestorUsuarios;
    delete gestorPrestamos;
	delete menuMateriales;
	delete menuUsuarios;
	delete menuPrestamos;
	delete menuReportes;
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

void MenuPrincipal::iniciar() {
  mostrarMenuPrincipal();
}

void MenuPrincipal::mostrarMenuPrincipal() {
  int opcion;
  bool salir=false;

  while(!salir) {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          SISTEMA DE GESTION DE BIBLIOTECA     \n";
    std::cout << "==============================================\n";
    std::cout << "1. Gestion de Materiales\n";
    std::cout << "2. Gestion de Usuarios\n";
    std::cout << "3. Gestion de Prestamos\n";
    std::cout << "4. Reportes\n";
    std::cout << "0. Salir\n";
    std::cout << "==============================================\n";
    std::cout << "Seleccione una opcion: ";

    if (!(std::cin >> opcion)) { //por si se ingresa algo fallido
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout<<"Opcion no valida!"<<std::endl;
      pausar();
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//limpia basura si es q quedo

    switch (opcion) {
      case 1:
        menuMateriales->mostrarMenu();
        break;
      case 2:
        menuUsuarios->mostrarMenu();
        break;
      case 3:
       menuPrestamos->mostrarMenu();
        break;
      case 4:
       menuReportes->mostrarMenu();
        break;
      case 0:
        std::cout << "Guardando datos...\n";
        guardarDatos();
        std::cout << "Hasta pronto!\n";
        salir = true;
        break;
      default:
        std::cout<<"Opcion no valida!"<<std::endl;
        pausar();
        break;
    }
  }
}