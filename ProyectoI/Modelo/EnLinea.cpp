//
// Created by ugald on 11/4/2025.
//

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