//
// Created by Roy Arias on 23/4/2025.
//

#include "Serializacion.h"

enum TipoMaterial {
    TIPO_LIBRO,
    TIPO_REVISTA,
    TIPO_DIGITAL_ENLINEA,
    TIPO_DIGITAL_FISICO,
};

void Serializacion::escribir_String(std::ofstream& archivo, const std::string& str) {
    size_t longS = str.size();
    archivo.write(reinterpret_cast<const char*>(&longS), sizeof(longS));
    archivo.write(str.c_str(), longS);
}

std::string Serializacion::leer_String(std::ifstream &archivo) {
    size_t longS;
    archivo.read(reinterpret_cast<char*>(&longS), sizeof(longS));
    std::string str(longS, '\0');
    archivo.read(&str[0], longS);

    return str;
}

void Serializacion::ser_Material(std::ofstream &archivo, const Material *material) {
    TipoMaterial tipo;

    if (dynamic_cast<const Libro*>(material)) {
        tipo = TIPO_LIBRO;
    } else if (dynamic_cast<const Revista*>(material)) {
        tipo = TIPO_REVISTA;
    } else if (dynamic_cast<const EnLinea*>(material)) {
        tipo = TIPO_DIGITAL_ENLINEA;
    } else if (dynamic_cast<const Fisico*>(material)) {
        tipo = TIPO_DIGITAL_FISICO;
    }

    archivo.write(reinterpret_cast<const char*>(&tipo), sizeof(tipo));
    int num_Clasificacion = material->get_num_clasificacion();
    int num_Catalogo = material->get_num_catalogo();
    archivo.write(reinterpret_cast<const char*>(&num_Clasificacion), sizeof(num_Clasificacion));
    archivo.write(reinterpret_cast<const char*>(&num_Catalogo), sizeof(num_Catalogo));

    escribir_String(archivo, material->get_titulo());
    escribir_String(archivo, material->get_autores());
    escribir_String(archivo, material->get_palabras_clave());
    escribir_String(archivo, material->get_tipo_material());
    escribir_String(archivo, material->get_estado_material());
}

void Serializacion::des_Material(std::ifstream &archivo, DatosMaterial &datos){

    archivo.read(reinterpret_cast<char*>(&datos.numClasificacion), sizeof(datos.numClasificacion));
    archivo.read(reinterpret_cast<char*>(&datos.numCatalogo), sizeof(datos.numCatalogo));

    datos.titulo = leer_String(archivo);
    datos.autores = leer_String(archivo);
    datos.palabrasClave = leer_String(archivo);
    datos.tipoMaterial = leer_String(archivo);
    datos.estadoMaterial = leer_String(archivo);
}

void Serializacion::ser_Libro(std::ofstream &archivo, const Libro *libro) {
    ser_Material(archivo,libro);
    escribir_String(archivo, libro->get_ubicacion());
}

Material *Serializacion::des_Libro(std::ifstream &archivo) {
    DatosMaterial datos;
    des_Material(archivo, datos);
    std::string ubicacion = leer_String(archivo);

    return new Libro(datos.numClasificacion,
        datos.numCatalogo,
        datos.titulo,
        datos.autores,
        datos.palabrasClave,
        datos.tipoMaterial,
        datos.estadoMaterial,
        ubicacion);
}

void Serializacion::ser_Revista(std::ofstream &archivo, const Revista *revista) {
    ser_Material(archivo,revista);
    int volumen = revista->get_volumen();
    int numero = revista->get_numero();
    archivo.write(reinterpret_cast<const char*>(&volumen), sizeof(volumen));
    archivo.write(reinterpret_cast<const char*>(&numero), sizeof(numero));
    escribir_String(archivo, revista->get_ubicacion());
}

Material *Serializacion::des_Revista(std::ifstream &archivo) {
    DatosMaterial datos;
    des_Material(archivo, datos);
    int volumen;
    int numero;
    archivo.read(reinterpret_cast<char*>(&volumen), sizeof(volumen));
    archivo.read(reinterpret_cast<char*>(&numero), sizeof(numero));
    std::string ubicacion = leer_String(archivo);

    return new Revista(datos.numClasificacion,
        datos.numCatalogo,
        datos.titulo,
        datos.autores,
        datos.palabrasClave,
        datos.tipoMaterial,
        datos.estadoMaterial,
        ubicacion, numero, volumen);
}

void Serializacion::ser_MaterialDigital(std::ofstream &archivo, const MaterialDigital *material) {
    ser_Material(archivo, material);
    escribir_String(archivo, material->get_tipo_formato());

    if (dynamic_cast<const EnLinea*>(material)) {

        bool acceso = dynamic_cast<const EnLinea*>(material)->get_acceso();
        archivo.write(reinterpret_cast<const char*>(&acceso), sizeof(acceso));

    } else if (dynamic_cast<const Fisico*>(material)) {

        std::string estilo_formato = dynamic_cast<const Fisico*>(material)->get_estilo_formato();
        escribir_String(archivo, estilo_formato);

    } else {
        throw;
    }
}

Material* Serializacion::des_MaterialDigital(std::ifstream& archivo) {
    DatosMaterial datos;
    des_Material(archivo, datos);
    std::string tipo_formato = leer_String(archivo);
    bool acceso;
    std::string estilo_formato;
    if (tipo_formato == "EnLinea") {
        archivo.read(reinterpret_cast<char*>(&acceso), sizeof(acceso));
        return new EnLinea(datos.numClasificacion,
            datos.numCatalogo,
            datos.titulo,
            datos.autores,
            datos.palabrasClave,
            datos.tipoMaterial,
            datos.estadoMaterial,
            tipo_formato, acceso);
    } else if (tipo_formato == "Fisico") {
        estilo_formato = leer_String(archivo);
        return new Fisico(datos.numClasificacion,
            datos.numCatalogo,
            datos.titulo,
            datos.autores,
            datos.palabrasClave,
            datos.tipoMaterial,
            datos.estadoMaterial,
            tipo_formato, estilo_formato);
    } else {
        throw;
    }
}

void Serializacion::ser_Usuario(std::ofstream &archivo, const Usuario *usuario) {
    escribir_String(archivo, usuario->getNombreCompleto());
    int cedula = usuario->getCedula();
    archivo.write(reinterpret_cast<const char*>(&cedula), sizeof(cedula));
    bool estado = usuario->getEstado();
    archivo.write(reinterpret_cast<const char*>(&estado), sizeof(estado));
}

Usuario* Serializacion::des_Usuario(std::ifstream &archivo) {
    std::string nombreCompleto = leer_String(archivo);
    int cedula;
    archivo.read(reinterpret_cast<char*>(&cedula), sizeof(cedula));
    bool estado;
    archivo.read(reinterpret_cast<char*>(&estado), sizeof(estado));

    return new Usuario(cedula, nombreCompleto, estado);
}





