//
// Created by Roy Arias on 23/4/2025.
//

#ifndef SERIALIZACION_H
#define SERIALIZACION_H

#include <iostream>
#include <fstream>
#include "Material.h"
#include "Libro.h"
#include "Revista.h"
#include "MaterialDigital.h"
#include "EnLinea.h"
#include "Fisico.h"


struct DatosMaterial {
    int numClasificacion;
    int numCatalogo;
    std::string titulo;
    std::string autores;
    std::string palabrasClave;
    std::string tipoMaterial;
    std::string estadoMaterial;
};


class Serializacion {
private:
    //Escritura y lectura de string
    static void escribir_String(std::ofstream& archivo, const std::string& str);
    static std::string leer_String(std::ifstream& archivo);

    static void ser_Material(std::ofstream& archivo, const Material* material);
    static void des_Material(std::ifstream& archivo, DatosMaterial &datos);

public:

    static void ser_Libro(std::ofstream& archivo, const Libro* libro);
    static Material* des_Libro(std::ifstream& archivo);

    static void ser_Revista(std::ofstream& archivo, const Revista* revista);
    static Material* des_Revista(std::ifstream& archivo);

    static void ser_MaterialDigital(std::ofstream& archivo, const MaterialDigital* material);
    static Material* des_MaterialDigital(std::ifstream& archivo);

};



#endif //SERIALIZACION_H
