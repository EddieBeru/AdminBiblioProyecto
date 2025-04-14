//
// Created by arias on 4/11/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <ostream>
#include <string>


class Material {
protected:
    int numClasificacion;
    int numCatalogo;
    std::string titulo;
    std::string autores;
    std::string palabrasClave;
    std::string tipoMaterial;
    std::string estadoMaterial;
public:
    // Constructor
    Material(
        const int numClasificacion = 0,
        const int numCatalogo = 0,
        const std::string &titulo = "",
        const std::string &autores = "",
        const std::string &palabrasClave = "",
        const std::string &tipoMaterial = "",
        const std::string &estadoMaterial = "");
    // Destructor
    virtual ~Material();

    //setters y getters
    int get_num_clasificacion() const;
    void set_num_clasificacion(const int num_clasificacion);

    int get_num_catalogo() const;
    void set_num_catalogo(const int num_catalogo);

    std::string get_titulo() const;
    void set_titulo(const std::string &titulo);

    std::string get_autores() const;
    void set_autores(const std::string &autores);

    std::string get_palabras_clave() const;
    void set_palabras_clave(const std::string &palabras_clave);

    std::string get_tipo_material() const;
    void set_tipo_material(const std::string &tipo_material);

    std::string get_estado_material() const;
    void set_estado_material(const std::string &estado_material);

    //Metodos virtuales
    virtual std::string getTipo() const = 0; //Metodo virtual puro para obtener el tipo de material
    virtual int getDuracionPrestamo() const = 0; //Metodo virtual puro para obtener la duracion del prestamo, se va a trabajar por dias


    //Sobre carga del operador de salida, y metodo para imprimir el objeto
    friend std::ostream & operator<<(std::ostream &os, const Material &obj);

    //Metodo virtual puro para imprimir el objeto, asi se evita repetir
    //la sobrecarga del operador de salida en cada clase hija
    virtual std::string imprimir() const = 0;

<<<<<<< HEAD
    friend bool operator<(const Material &a, const Material &b);

    friend bool operator<=(const Material &a, const Material &b);
    friend bool operator>(const Material &a, const Material &b);
    friend bool operator>=(const Material &a, const Material &b);
    friend bool operator==(const Material &a, const Material &b);
    friend bool operator!=(const Material &a, const Material &b);

=======
    //Multiples operadores de comparación, no es recomendable hacerlo virtual puro
	//así que mejor dejarlo que otras clases lo hereden.
    friend bool operator<(const Material& a, const Material& b);
    friend bool operator<=(const Material& a, const Material& b);
    friend bool operator>(const Material& a, const Material& b);
    friend bool operator>=(const Material& a, const Material& b);
    friend bool operator==(const Material& a, const Material& b);
    friend bool operator!=(const Material& a, const Material& b);
    
>>>>>>> PruebaOperadores
};

#endif //MATERIAL_H
