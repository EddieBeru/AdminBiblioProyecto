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

#include "GestorMateriales.h"

Contenedor<Material> * GestorMateriales::get_lista_materiales() const {
    return listaMateriales;
}

GestorMateriales::GestorMateriales(){
    listaMateriales = new Contenedor<Material>();
}

void GestorMateriales::agregarMaterial(Material *material) {
    listaMateriales->agregarFinal(new Nodo<Material>(material));
}

Material *GestorMateriales::buscarMaterialPorTitulo(const std::string &titulo) const {
    try {
        Material* mat = listaMateriales->find_if([&](Material* m) {
            if (auto matAux = dynamic_cast<Material*>(m)) {
                return matAux->get_titulo() == titulo;
            }
            return false;
            });
        return static_cast<Material*>(mat);
    }
    catch (NodoNoEncontrado &ex) {
        throw ex.what();
    }
    catch (std::exception& ex) {
		throw;
	}
    
}

std::ostream& operator<<(std::ostream& os, const GestorMateriales& a) {
    return os << "Lista de materiales:\n" << *a.listaMateriales << std::endl;
}

Material *GestorMateriales::buscarMaterialPorClasificacion(const int numClasificacion) const {
    try {
        Material *mat = listaMateriales->find_if([&](Material *m) {
           if (auto matAux = dynamic_cast<Material *>(m)) {
               return matAux->get_num_clasificacion() == numClasificacion;
           }
            return false;
        });
        return static_cast<Material *>(mat);
    }
    catch (NodoNoEncontrado& ex) {
        throw;
    }
    catch (std::exception& ex) {
        throw;
    }
}

bool GestorMateriales::modificarMaterial(int numClasificacion, const Material &datosNuevos) {
   try {
        Material* matMod = buscarMaterialPorClasificacion(numClasificacion);
        if (matMod->get_num_clasificacion() == numClasificacion) {
            matMod->set_num_catalogo(datosNuevos.get_num_catalogo());
            matMod->set_titulo(datosNuevos.get_titulo());
            matMod->set_autores(datosNuevos.get_autores());
            matMod->set_palabras_clave(datosNuevos.get_palabras_clave());
            matMod->set_tipo_material(datosNuevos.get_tipo_material());
            matMod->set_estado_material(datosNuevos.get_estado_material());
            return true;
        }
        else {
            return false;
		}
	}
	catch (NodoNoEncontrado& ex) {
        throw;
    }
	catch (std::exception& ex) {
		throw;
	}
   
}

bool GestorMateriales::modificarLibro(int numClasificacion, const Libro &datosNuevos) {
   try {
       Libro* libMod = dynamic_cast<Libro*>(buscarMaterialPorClasificacion(numClasificacion));
        if (libMod->get_num_clasificacion() == numClasificacion) {
            modificarMaterial(numClasificacion, datosNuevos);
            libMod->set_ubicacion(datosNuevos.get_ubicacion());
            return true;
        }
        else {
            return false;
       }
	}
	catch (NodoNoEncontrado& ex) {
		throw;
	}
    catch (std::exception& ex) {
        throw;
    }
    
}

bool GestorMateriales::modificarRevista(int numClasificacion, const Revista &datosNuevos) {
    try {
        Revista* revMod = dynamic_cast<Revista*>(buscarMaterialPorClasificacion(numClasificacion));
        if (revMod->get_num_clasificacion() == numClasificacion) {
            modificarMaterial(numClasificacion, datosNuevos);
            revMod->set_numero(datosNuevos.get_numero());
            revMod->set_volumen(datosNuevos.get_volumen());
            revMod->set_ubicacion(datosNuevos.get_ubicacion());
            return true;
        }
        else {
            return false;
        }
    } catch (NodoNoEncontrado& ex) {
		throw;
	}
    catch (std::exception& ex) {
        throw;
    }
}

bool GestorMateriales::modificarDigital(int numClasificacion, const MaterialDigital &datosNuevos) {
    try {
        MaterialDigital* matDigMod = dynamic_cast<MaterialDigital*>(buscarMaterialPorClasificacion(numClasificacion));
        if (matDigMod->get_num_clasificacion() == numClasificacion) {
            modificarMaterial(numClasificacion, datosNuevos);
            matDigMod->set_tipo_formato(datosNuevos.get_tipo_formato());
            return true;
        }
        else {
            return false;
        }
    }
    catch (NodoNoEncontrado& ex) {
        throw;
    }
    catch (std::exception& ex) {
        throw;
    }
}

bool GestorMateriales::modificarFisico(int numClasificacion, const Fisico &datosNuevos) {
    try {
        Fisico* fisMod = dynamic_cast<Fisico*>(buscarMaterialPorClasificacion(numClasificacion));
        if (fisMod->get_num_clasificacion() == numClasificacion) {
            modificarDigital(numClasificacion, datosNuevos);
            fisMod->set_estilo_formato(datosNuevos.get_estilo_formato());
            return true;
        }
        else {
            return false;
        }
    }
    catch (NodoNoEncontrado& ex) {
        throw;
    }
    catch (std::exception& ex) {
        throw;
    }
}

bool GestorMateriales::modificarEnLinea(int numClasificacion, const EnLinea &datosNuevos) {
    try {
        EnLinea* enLinMod = dynamic_cast<EnLinea*>(buscarMaterialPorClasificacion(numClasificacion));
        if (enLinMod->get_num_clasificacion() == numClasificacion) {
            modificarDigital(numClasificacion, datosNuevos);
            enLinMod->set_acceso(datosNuevos.get_acceso());
            return true;
        }
        else {
            return false;
        }
    }
    catch (NodoNoEncontrado& ex) {
        throw;
    }
    catch (std::exception& ex) {
        throw;
    }
}

Material* GestorMateriales::obtener_material(int index) {
    return listaMateriales->buscar(index)->getItem();
}

