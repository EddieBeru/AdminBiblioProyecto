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
#ifndef MATERIALDIGITAL_H
#define MATERIALDIGITAL_H

#include "Material.h"



class MaterialDigital : public Material {
protected:

    std::string tipoFormato;
public:
    MaterialDigital(int numClasificacion = 0, int numCatalogo = 0, const std::string &titulo = "", const std::string &autores = "",
        const std::string &palabrasClave = "", const std::string &tipoMaterial = "", const std::string &estadoMaterial = "",
        const std::string &tipo_formato = "")
        : Material(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial),
          tipoFormato(tipo_formato) {
    }

    std::string get_tipo_formato() const;

    void set_tipo_formato(const std::string &tipo_formato);

    //metodos virtuales heredados de la clase padre
     int getDuracionPrestamo() const override;
     std::string getTipo() const override;
     std::string imprimir() const override;
};


#endif //MATERIALDIGITAL_H
