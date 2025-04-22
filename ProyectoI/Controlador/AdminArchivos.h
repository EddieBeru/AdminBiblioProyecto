//
// Created by arias on 4/21/2025.
//

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
