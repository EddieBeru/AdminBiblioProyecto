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
        }
    }
    archivo.close();
}


void AdminArchivos::guardarUsuarios(GestorUsuarios &gestor) {

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
            }
        if (mat) {
            gestor.agregarMaterial(mat);
        }
    }
    archivo.close();
}

void AdminArchivos::cargarUsuarios(GestorUsuarios &gestor) {

}

