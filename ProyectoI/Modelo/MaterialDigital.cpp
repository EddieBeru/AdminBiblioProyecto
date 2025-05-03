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
#include "MaterialDigital.h"

std::string MaterialDigital::get_tipo_formato() const {
    return tipoFormato;
}

void MaterialDigital::set_tipo_formato(const std::string &tipo_formato) {
    tipoFormato = tipo_formato;
}

int MaterialDigital::getDuracionPrestamo() const {
    return 5; //se prestan a lo mucho 5 dias
}

std::string MaterialDigital::getTipo() const {
    return "Material Digital: ";
}

std::string MaterialDigital::imprimir() const {
    return "Material Digital: " + std::to_string(get_num_clasificacion()) + ", " + std::to_string(get_num_catalogo()) + ", " + titulo + ", " +
           autores + ", " + palabrasClave + ", " + tipoMaterial + ", " + estadoMaterial + ", " + tipoFormato;
}

