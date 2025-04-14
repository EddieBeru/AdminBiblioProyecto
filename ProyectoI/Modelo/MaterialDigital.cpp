//
// Created by ugald on 11/4/2025.
//
#include "MaterialDigital.h"

<<<<<<< HEAD
std::string MaterialDigital::get_tipo_formato() const {
    return tipoFormato;
}

void MaterialDigital::set_tipo_formato(const std::string &tipo_formato) {
=======
string MaterialDigital::get_tipo_formato() const {
    return tipoFormato;
}

void MaterialDigital::set_tipo_formato(const string &tipo_formato) {
>>>>>>> PruebaOperadores
    tipoFormato = tipo_formato;
}

int MaterialDigital::getDuracionPrestamo() const {
    return 5; //se prestan a lo mucho 5 dias
}

<<<<<<< HEAD
std::string MaterialDigital::getTipo() const {
    return "Material Digital: ";
}

std::string MaterialDigital::imprimir() const {
    return "Material Digital: " + std::to_string(get_num_clasificacion()) + ", " + std::to_string(get_num_catalogo()) + ", " + titulo + ", " +
           autores + ", " + palabrasClave + ", " + tipoMaterial + ", " + estadoMaterial + ", " + tipoFormato;
}
=======
string MaterialDigital::getTipo() const {
    return "Material Digital: ";
}

string MaterialDigital::imprimir() const {
    return "Material Digital: " + std::to_string(get_num_clasificacion()) + ", " + std::to_string(get_num_catalogo()) + ", " + titulo + ", " +
           autores + ", " + palabrasClave + ", " + tipoMaterial + ", " + estadoMaterial + ", " + tipoFormato;
}

>>>>>>> PruebaOperadores
