//
// Created by ugald on 11/4/2025.
//

#ifndef MATERIALDIGITAL_H
#define MATERIALDIGITAL_H

#include "Material.h"

class MaterialDigital : public Material {
private:
    string tipoFormato;
    public:
    MaterialDigital(int numClasificacion, int numCatalogo, const std::string &autores, const std::string &palabrasClave,
        const std::string &tipoMaterial, const std::string &estadoMaterial, const string &tipo_formato)
        : Material(numClasificacion, numCatalogo, autores, palabrasClave, tipoMaterial, estadoMaterial),
          tipoFormato(tipo_formato) {
    }

    string get_tipo_formato() const;

    void set_tipo_formato(const string &tipo_formato);

    //metodos virtuales heredados de la clase padre
    virtual int getDuracionPrestamo() const override;
    virtual string getTipo() const override;

    virtual string imprimir() const override;
};



#endif //MATERIALDIGITAL_H
