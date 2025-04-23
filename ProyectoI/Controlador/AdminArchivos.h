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

struct DatosMaterial {
    int numClasificacion;
    int numCatalogo;
    std::string titulo;
    std::string autores;
    std::string palabrasClave;
    std::string tipoMaterial;
    std::string estadoMaterial;
};

class AdminArchivos {
private:
    //Escritura y lectura de string
    static void escribir_String(std::ofstream& archivo, const std::string& str);
    static std::string leer_String(std::ifstream& archivo);

    //Serializaciones de los objetos
    static void ser_Material(std::ofstream& archivo, const Material* material);
    static void des_Material(std::ifstream& archivo, DatosMaterial &datos);

    static void ser_Libro(std::ofstream& archivo, const Libro* libro);
    static Material* des_Libro(std::ifstream& archivo);

    static void ser_Revista(std::ofstream& archivo, const Revista* revista);
    static Material* des_Revista(std::ifstream& archivo);

    static void ser_MaterialDigital(std::ofstream& archivo, const MaterialDigital* material);
    static Material* des_MaterialDigital(std::ifstream& archivo);

    static void ser_EnLinea(std::ofstream& archivo, const EnLinea* enlinea);
    static Material* des_EnLinea(std::ifstream& archivo);

    static void ser_Fisico(std::ofstream& archivo, const Fisico* fisico);
    static Material* des_Fisico(std::ifstream& archivo);


public:

    //metodos guardar
    static void guardarMateriales(GestorMateriales& gestor);
    static void guardarUsuarios(GestorUsuarios& gestor);

    //metodos cargar
    static void cargarMateriales(GestorMateriales& gestor);
    static void cargarUsuarios(GestorUsuarios& gestor);
};



#endif //ADMINARCHIVOS_H
