/*
* (c) 2025
* EIF204 - Programaci�n 2
* 1er Ciclo - 2025
* NRC 41372 - Grupo 8
* Proyecto 1
* 
* 6-0499-0591; Berm�dez Ure�a, Edie
* 4-0264-0704; Arias Med�a, Roy
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
private:
    //Escritura y lectura de string
    static void escribir_String(std::ofstream& archivo, const std::string& str);
    static std::string leer_String(std::ifstream& archivo);

    //Serializaciones de los objetos
    static void des_Libro(std::ofstream& archivo, const Libro* libro);
    static Libro* ser_Libro(std::ifstream& archivo);

public:

    //metodos guardar
    static void guardarMateriales(GestorMateriales& gestor);
    static void guardarUsuarios(GestorUsuarios& gestor);

    //metodos cargar
    static void cargarMateriales(GestorMateriales& gestor);
    static void cargarUsuarios(GestorUsuarios& gestor);
};



#endif //ADMINARCHIVOS_H
