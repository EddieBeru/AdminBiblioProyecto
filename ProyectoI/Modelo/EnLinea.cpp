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

#include "EnLinea.h"

EnLinea::EnLinea(int numClasificacion, int numCatalogo, const std::string &titulo, const std::string &autores,
    const std::string &palabrasClave, const std::string &tipoMaterial, const std::string &estadoMaterial,
    const std::string &tipo_formato, bool acceso)
    : MaterialDigital(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipo_formato),
      acceso(acceso) {}

bool EnLinea::get_acceso() const {
    return acceso;
}

void EnLinea::set_acceso(bool acceso) {
    this->acceso = acceso;
}

std::string EnLinea::getTipo() const {
    return "EnLinea";
}

std::string EnLinea::imprimir() const {
    return "Material digital en linea:\n\t\tClasificacion: " + std::to_string(numClasificacion) +
           "\n\t\tCatalogo: " + std::to_string(numCatalogo) +
           "\n\t\tTitulo: " + titulo +
           "\n\t\tAutor(es): " + autores +
           "\n\t\tPalabras clave: " + palabrasClave +
           "\n\t\tTipo de material: " + tipoMaterial +
           "\n\t\tEstado: " + estadoMaterial +
           "\n\t\tFormato: " + tipoFormato +
           "\n\t\tAcceso: " + (acceso ? "Habilitado" : "Deshabilitado");
}