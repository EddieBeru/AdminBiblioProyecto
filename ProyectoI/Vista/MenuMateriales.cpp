//
// Created by ugald on 24/4/2025.
//

#include "MenuMateriales.h"
#include "../Modelo/Libro.h"
#include "../Modelo/Revista.h"
#include "../Modelo/EnLinea.h"
#include "../Modelo/Fisico.h"
#include <iostream>
#include <cstdlib>


MenuMateriales::MenuMateriales(GestorMateriales *gestorMateriales): gestor(gestorMateriales) {}

MenuMateriales::~MenuMateriales() {}

void MenuMateriales::limpiarPantalla() {
    std::system("cls");
}

void MenuMateriales::pausar() {
    std::cout<<"Presiones Enter para continuar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int MenuMateriales::solicitarEntero(const std::string &mensaje) {
    int valor;
    while (true) {
        std::cout<<mensaje;
        if (std::cin>>valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Error: Ingrese un numero entero valido\n";
        }
    }
}

std::string MenuMateriales::solicitarTexto(const std::string &mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void MenuMateriales::mostrarMenu() {
    int opcion;
    bool volver=false;

    while (!volver) {
        limpiarPantalla();
        std::cout << "\n==============================================\n";
        std::cout << "          GESTION DE MATERIALES               \n";
        std::cout << "==============================================\n";
        std::cout << "1. Incluir Material\n";
        std::cout << "2. Modificar Material\n";
        std::cout << "3. Mostrar Todos los Materiales\n";
        std::cout << "4. Buscar Material\n";
        std::cout << "0. Volver al Menu Principal\n";
        std::cout << "==============================================\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Opcion no valido\n";
            pausar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //limpia basura si es q quedo

        switch (opcion){
            case 1:
                agregarMaterial();
                break;
            case 2:
                modificarMaterial();
                break;
            case 3:
                mostrarMateriales();
                break;
            case 4:
                buscarMaterial();
                break;
            case 0:
                volver=true;
                break;
            default:
                std::cout<<"Opcion no valido\n";
                pausar();
                break;
        }
    }
}

void MenuMateriales::agregarMaterial() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          INCLUIR MATERIAL                    \n";
    std::cout << "==============================================\n";
    std::cout << "1. Libro\n";
    std::cout << "2. Revista\n";
    std::cout << "3. Material Digital En Línea\n";
    std::cout << "4. Material Digital Físico\n";
    std::cout << "0. Volver\n";
    std::cout << "==============================================\n";

    int opcion=solicitarEntero("Seleccione el tipo de material:");

    switch (opcion) {
        case 1:
            agregarLibro();
            break;
        case 2:
            agregarRevista();
            break;
        case 3:
            agregarDigitalEnLinea();
            break;
        case 4:
            agregarDigitalFisico();
            break;
        case 0:
            return;
        default:
            std::cout<<"Opcion no valido\n";
            pausar();
            return;
    }
}

void MenuMateriales::agregarLibro() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          AGREGAR LIBRO                       \n";
    std::cout << "==============================================\n";

    int numClasificacion=solicitarEntero("Numero de clasificaciones:");
    int numCatalogo=solicitarEntero("Numero de catalogos:");
    std::string titulo=solicitarTexto("Titulo:");
    std::string autores=solicitarTexto("Autor:");
    std::string palabrasClave=solicitarTexto("Palabras Clave (separadas ,):");
    std::string tipoMaterial=solicitarTexto("Tipo de Material:");
    std::string estadoMaterial=solicitarTexto("Estado de Material(Disponible/Prestado:");
    std::string ubicacion=solicitarTexto("Ubicacion:");

    try {
        Libro* libro=new Libro(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, ubicacion);
        gestor->agregarMaterial(libro);
        std::cout<<"Libro ha sido agregado\n";
    }catch (const std::exception& e) {
        std::cerr<<"Error al agregar libro: "<<e.what()<<std::endl;
    }

    pausar();
}

void MenuMateriales::agregarRevista() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          AGREGAR REVISTA                     \n";
    std::cout << "==============================================\n";

    int numClasificacion = solicitarEntero("Numero de clasificacion:");
    int numCatalogo = solicitarEntero("Numero de catalogo:");
    std::string titulo = solicitarTexto("Titulo:");
    std::string autores = solicitarTexto("Autor:");
    std::string palabrasClave = solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial = solicitarTexto("Tipo de material:");
    std::string estadoMaterial = solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string ubicacion = solicitarTexto("Ubicacion:");
    int numero = solicitarEntero("Numero de la revista:");
    int volumen = solicitarEntero("Volumen de la revista:");

    try {
        Revista* revista = new Revista(numClasificacion, numCatalogo, titulo, autores, palabrasClave,
                                       tipoMaterial, estadoMaterial, ubicacion, numero, volumen);
        gestor->agregarMaterial(revista);
        std::cout << "Revista ha sido agregada\n";
    } catch (const std::exception& e) {
        std::cerr << "Error al agregar revista: " << e.what() << std::endl;
    }

    pausar();
}

void MenuMateriales::agregarDigitalEnLinea() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "      AGREGAR MATERIAL DIGITAL EN LINEA       \n";
    std::cout << "==============================================\n";

    int numClasificacion = solicitarEntero("Numero de clasificacion:");
    int numCatalogo = solicitarEntero("Numero de catalogo:");
    std::string titulo = solicitarTexto("Titulo:");
    std::string autores = solicitarTexto("Autor:");
    std::string palabrasClave = solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial = solicitarTexto("Tipo de material:");
    std::string estadoMaterial = solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string tipoFormato= solicitarTexto("Tipo formato:");

    std::string accesoTexto = solicitarTexto("Tiene Acceso? (s/n):"); //s de si, n de no
    bool acceso =(accesoTexto =="s"  || accesoTexto =="S"); //minuscula o mayuscula de Si, si es alguna de esas se toma como true, sino es false

    try {
        EnLinea* enLinea = new EnLinea(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipoFormato, acceso);
        gestor->agregarMaterial(enLinea);
        std::cout<<"Material Digital ha sido agregado\n";
    }catch (const std::exception& e) {
        std::cerr << "Error al agregar material digital en linea: " << e.what() << std::endl;
    }

    pausar();
}

void MenuMateriales::agregarDigitalFisico() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "      AGREGAR MATERIAL DIGITAL FISICO         \n";
    std::cout << "==============================================\n";

    int numClasificacion = solicitarEntero("Numero de clasificacion:");
    int numCatalogo = solicitarEntero("Numero de catalogo:");
    std::string titulo = solicitarTexto("Titulo:");
    std::string autores = solicitarTexto("Autor:");
    std::string palabrasClave = solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial = solicitarTexto("Tipo de material:");
    std::string estadoMaterial = solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string tipoFormato= solicitarTexto("Tipo formato:");
    std::string estiloFormato = solicitarTexto("Estilo formato:");

    try {
        Fisico* fisico = new Fisico(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipoFormato, estiloFormato);
        gestor->agregarMaterial(fisico);
        std::cout<<"Material Digital ha sido agregado\n";
    }catch (const std::exception& e) {
        std::cerr << "Error al agregar material digital fisico: " << e.what() << std::endl;
    }

    pausar();
}

void MenuMateriales::modificarMaterial() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          MODIFICAR MATERIAL                  \n";
    std::cout << "==============================================\n";

    int numClasificacion= solicitarEntero("Numero de clasificacion de material a modificar:");

    try {
        Material* material=gestor->buscarMaterialPorClasificacion(numClasificacion); //se busca el material

        std::cout<<"Material encontrado\n";
        std::cout<< material->imprimir();

        std::string tipo=material->getTipo();

        if (tipo == "Libro") { //se busca que tipo de material es y se llama el metodo que es
            modificarLibro(numClasificacion);
        }else if (tipo == "Revista") {
            modificarRevista(numClasificacion);
        }else if (tipo == "EnLinea") {
            modificarDigitalEnLinea(numClasificacion);
        }else if (tipo == "Fisico") {
            modificarDigitalFisico(numClasificacion);
        }else {
            std::cout<<"Tipo de material no encontrado\n";
        }
    }catch (const std::exception& e) {
        std::cerr<<"Error: "<<e.what()<<std::endl;
    }

    pausar();
}


void MenuMateriales::modificarLibro(int numClasificacion) {
    std::cout<<"Se ve a ingresar los nuevos datos para el libro:"<<std::endl;

    int numCatalogo= solicitarEntero("Numero de catalogo:");
    std::string titulo= solicitarTexto("Titulo:");
    std::string autores= solicitarTexto("Autor:");
    std::string palabrasClave= solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial= solicitarTexto("Tipo de material:");
    std::string estadoMaterial= solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string ubicacion= solicitarTexto("Ubicacion:");

    try {
        Libro libroModificado(numClasificacion, numCatalogo, titulo, autores, palabrasClave,tipoMaterial, estadoMaterial, ubicacion);
        if (gestor->modificarLibro(numClasificacion, libroModificado)) {
            std::cout<<"libro ha sido modificado\n";
        }else {
            std::cout<<"No se pudo modificar libro\n";
        }
    }catch (const std::exception& e) {
        std::cerr<<"Error al modificar libro: "<<e.what()<<std::endl;
    }
}


void MenuMateriales::modificarRevista(int numClasificacion) {
    std::cout<<"Se ve a ingresar los nuevos datos para la revista:"<<std::endl;

    int numCatalogo= solicitarEntero("Numero de catalogo:");
    std::string titulo= solicitarTexto("Titulo:");
    std::string autores= solicitarTexto("Autor:");
    std::string palabrasClave= solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial= solicitarTexto("Tipo de material:");
    std::string estadoMaterial= solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string ubicacion= solicitarTexto("Ubicacion:");
    int numero = solicitarEntero("Numero de la revista:");
    int volumen = solicitarEntero("Volumen de la revista:");

    try {
        Revista revistaModificada(numClasificacion, numCatalogo, titulo, autores, palabrasClave,
                                       tipoMaterial, estadoMaterial, ubicacion, numero, volumen);
        if (gestor->modificarRevista(numClasificacion, revistaModificada)) {
            std::cout<<"Revista ha sido modificada\n";
        }else {
            std::cout<<"No se pudo modificar Revista\n";
        }
    }catch (const std::exception& e) {
        std::cerr<<"Error al modificar la revista: "<<e.what()<<std::endl;
    }
}

void MenuMateriales::modificarDigitalEnLinea(int numClasificacion) {
    std::cout<<"Se ve a ingresar los nuevos datos para el material digital en linea:"<<std::endl;

    int numCatalogo = solicitarEntero("Numero de catalogo:");
    std::string titulo = solicitarTexto("Titulo:");
    std::string autores = solicitarTexto("Autor:");
    std::string palabrasClave = solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial = solicitarTexto("Tipo de material:");
    std::string estadoMaterial = solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string tipoFormato= solicitarTexto("Tipo formato:");

    std::string accesoTexto = solicitarTexto("Tiene Acceso? (s/n):"); //s de si, n de no
    bool acceso =(accesoTexto =="s"  || accesoTexto =="S");


    try {
        EnLinea enLineaModificada(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipoFormato, acceso);
        if (gestor->modificarEnLinea(numClasificacion, enLineaModificada)) {
            std::cout<<"Material digital en linea modificado\n";
        }else {
            std::cout<<"No se pudo modificar EnLinea\n";
        }
    }catch (const std::exception& e) {
        std::cerr<<"Error al modificar el material digital en linea: "<<e.what()<<std::endl;
    }
}

void MenuMateriales::modificarDigitalFisico(int numClasificacion) {
    std::cout<<"Se ve a ingresar los nuevos datos para el material digital fisico:"<<std::endl;

    int numCatalogo = solicitarEntero("Numero de catalogo:");
    std::string titulo = solicitarTexto("Titulo:");
    std::string autores = solicitarTexto("Autor:");
    std::string palabrasClave = solicitarTexto("Palabras clave (separadas ,):");
    std::string tipoMaterial = solicitarTexto("Tipo de material:");
    std::string estadoMaterial = solicitarTexto("Estado del material (Disponible/Prestado):");
    std::string tipoFormato= solicitarTexto("Tipo formato:");
    std::string estiloFormato = solicitarTexto("Estilo formato:");

    try {
        Fisico fisicoModificada(numClasificacion, numCatalogo, titulo, autores, palabrasClave, tipoMaterial, estadoMaterial, tipoFormato, estiloFormato);
        if (gestor->modificarFisico(numClasificacion, fisicoModificada)) {
            std::cout<<"Material Digital Fisico modificada\n";
        }else {
            std::cout<<"No se pudo modificar Fisico\n";
        }
    }catch (const std::exception& e) {
        std::cerr<<"Error al modificar el material digital fisico: "<<e.what()<<std::endl;
    }
}

void MenuMateriales::mostrarMateriales() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          MOSTRAR MATERIAL                    \n";
    std::cout << "==============================================\n";

//falta por avanzar
}
