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
    return "EnLinea: " + std::to_string(numClasificacion) + ", " + std::to_string(numCatalogo) + ", " +
           titulo + ", " + autores + ", " + palabrasClave + ", " + tipoMaterial + ", " +
           estadoMaterial + ", " + tipoFormato + ", " + (acceso ? "Acceso Publico" : "Acceso Restringido");
}
