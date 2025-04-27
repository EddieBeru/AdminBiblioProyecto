#include "AdminArchivos.h"

#include "GestorPrestamos.h"
#include "../Modelo/Serializacion.h"

enum TipoMaterial {
    TIPO_LIBRO,
    TIPO_REVISTA,
    TIPO_DIGITAL_ENLINEA,
    TIPO_DIGITAL_FISICO,
};

/*-------------------------------------------------------------------------------------------------------------------------------------*/

void AdminArchivos::guardarMateriales(GestorMateriales &gestor) {
    std::ofstream archivo("materiales.bin", std::ios::binary);

    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("materiales.bin");
    }

    for (int i = 0;  i < gestor.get_lista_materiales()->tamano(); i++) {
        Material* material = gestor.obtener_material(i);

        if (Libro* libro = dynamic_cast<Libro*>(material)) {
            Serializacion::ser_Libro(archivo, libro);
        } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
            Serializacion::ser_Revista(archivo, revista);
        } else if (EnLinea* enLinea = dynamic_cast<EnLinea*>(material)) {
            Serializacion::ser_MaterialDigital(archivo, enLinea);
        } else if (Fisico* fisico = dynamic_cast<Fisico*>(material)) {
            Serializacion::ser_MaterialDigital(archivo, fisico);
        } else {
            throw;
        }
    }
    archivo.close();
}


void AdminArchivos::guardarUsuarios(GestorUsuarios &gestor) {
    std::ofstream archivo("usuarios.bin", std::ios::binary);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("usuarios.bin");
    }
    for (int i = 0; i < gestor.get_lista_usuarios()->tamano(); i++) {
        Usuario* usuario = gestor.get_usuario(i);
        Serializacion::ser_Usuario(archivo, usuario);
    }
    archivo.close();
}

void AdminArchivos::cargarMateriales(GestorMateriales &gestor) {
 std::ifstream archivo("materiales.bin", std::ios::binary);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("materiales.bin");
    }

    TipoMaterial tipo;

    while (archivo.read(reinterpret_cast<char*>(&tipo), sizeof(tipo))) {
        Material* mat = nullptr;

            switch (tipo) {
                case TIPO_LIBRO:
                    mat = Serializacion::des_Libro(archivo);
                    break;
                case TIPO_REVISTA:
                    mat = Serializacion::des_Revista(archivo);
                    break;
                case TIPO_DIGITAL_ENLINEA:
                    mat = Serializacion::des_MaterialDigital(archivo);
                    break;
                case TIPO_DIGITAL_FISICO:
                    mat = Serializacion::des_MaterialDigital(archivo);
                    break;
                default:
                    throw ErrorTipoMaterialInvalido();
            }

        if (mat) {
            gestor.agregarMaterial(mat);
        }
    }
    archivo.close();
}

void AdminArchivos::cargarUsuarios(GestorUsuarios &gestor) {
    std::ifstream archivo("usuarios.bin", std::ios::binary);
    if (!archivo.is_open()) {
        throw ErrorAbrirArchivo("usuarios.bin");
    }
    while (archivo.peek() != EOF) {
        Usuario* usuario = Serializacion::des_Usuario(archivo);
        gestor.agregarUsuario(usuario);
    }
    archivo.close();
}

