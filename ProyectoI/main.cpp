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

#include <iostream>

#include "Modelo/Libro.h"
#include "Modelo/Nodo.h"
#include "Modelo/Contenedor.h"
#include "Controlador/GestorMateriales.h"
#include "Controlador/GestorPrestamos.h"
#include "Controlador/GestorUsuarios.h"
#include "Controlador/AdminArchivos.h"
#include "Vista/MenuPrincipal.h"

int main() {
	
	MenuPrincipal* menu = new MenuPrincipal();
	menu->iniciar();

	delete menu;
	return 0;
}

