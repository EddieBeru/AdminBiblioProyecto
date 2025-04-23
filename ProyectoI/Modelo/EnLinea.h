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
#ifndef ENLINEA_H
#define ENLINEA_H

#include "MaterialDigital.h"
#include <string>

class EnLinea : public MaterialDigital {
private:
    bool acceso;
public:
    EnLinea(int numClasificacion = 0, int numCatalogo = 0, const std::string &titulo = "", const std::string &autores = "",
        const std::string &palabrasClave = "", const std::string &tipoMaterial = "", const std::string &estadoMaterial = "",
        const std::string &tipo_formato = "", bool acceso = false);

    bool get_acceso() const;
    void set_acceso(bool acceso);

    virtual std::string getTipo() const override;
    virtual std::string imprimir() const override;
};

#endif // ENLINEA_H
