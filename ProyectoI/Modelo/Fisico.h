//
// Created by ugald on 11/4/2025.
//

#ifndef FISICO_H
#define FISICO_H

#include "MaterialDigital.h"
#include <string>

class Fisico : public MaterialDigital {
private:
    std::string estiloFormato;
public:
    Fisico(int numClasificacion = 0, int numCatalogo = 0, const std::string &titulo = "", const std::string &autores = "",
        const std::string &palabrasClave = "", const std::string &tipoMaterial = "", const std::string &estadoMaterial = "",
        const std::string &tipo_formato = "", const std::string &estilo_formato = "");

    std::string get_estilo_formato() const;
    void set_estilo_formato(const std::string &estilo_formato);

    virtual std::string getTipo() const override;
    virtual std::string imprimir() const override;
};

#endif // FISICO_H

<<<<<<< HEAD
#endif //FISICO_H
=======
>>>>>>> PruebaOperadores
