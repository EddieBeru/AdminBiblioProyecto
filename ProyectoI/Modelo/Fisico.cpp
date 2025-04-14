//
// Created by ugald on 11/4/2025.
//

#include "Fisico.h"

Fisico::Fisico(int numClasificacion, int numCatalogo, const std::string &titulo, const std::string &autores,
    const std::string &palabrasClave, const std::string &tipoMaterial, const std::string &estadoMaterial,
    const std::string &tipo_formato, const std::string &estilo_formato)
    : MaterialDigital(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipo_formato),
      estiloFormato(estilo_formato) {}

std::string Fisico::get_estilo_formato() const {
    return estiloFormato;
}

void Fisico::set_estilo_formato(const std::string &estilo_formato) {
    estiloFormato = estilo_formato;
}

std::string Fisico::getTipo() const {
    return "Fisico";
}

std::string Fisico::imprimir() const {
    return "Fisico: " + std::to_string(numClasificacion) + ", " + std::to_string(numCatalogo) + ", " +
           titulo + ", " + autores + ", " + palabrasClave + ", " + tipoMaterial + ", " +
           estadoMaterial + ", " + tipoFormato + ", " + estiloFormato;
}