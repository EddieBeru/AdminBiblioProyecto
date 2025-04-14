//
// Created by ugald on 11/4/2025.
//

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
