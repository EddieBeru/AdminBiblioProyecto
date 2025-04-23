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
#ifndef ADMINARCHIVOS_H
#define ADMINARCHIVOS_H
#include "GestorMateriales.h"
#include "GestorUsuarios.h"
#include <fstream>

class AdminArchivos {
public:

    //metodos guardar
    static void guardarMateriales(GestorMateriales& gestor);
    static void guardarUsuarios(GestorUsuarios& gestor);

    //metodos cargar
    static void cargarMateriales(GestorMateriales& gestor);
    static void cargarUsuarios(GestorUsuarios& gestor);
};



#endif //ADMINARCHIVOS_H
