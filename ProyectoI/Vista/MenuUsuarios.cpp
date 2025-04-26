//
// Created by ugald on 24/4/2025.
//

#include "MenuUsuarios.h"
#include "../Modelo/Usuario.h"
#include <iostream>
#include <cstdlib>

MenuUsuarios::MenuUsuarios(GestorUsuarios *gestorUsuarios) : gestor(gestorUsuarios){}

MenuUsuarios::~MenuUsuarios() {}

void MenuUsuarios::limpiarPantalla() {
    std::system("cls");
}

void MenuUsuarios::pausar() {
    std::cout<<"Presiones Enter para continuar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int MenuUsuarios::solicitarEntero(const std::string &mensaje) {
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

std::string MenuUsuarios::solicitarTexto(const std::string &mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void MenuUsuarios::mostrarMenu() {
    int opcion;
    bool volver=false;

    while (!volver) {
        limpiarPantalla();
        std::cout << "\n==============================================\n";
        std::cout << "          GESTIÓN DE USUARIOS                \n";
        std::cout << "==============================================\n";
        std::cout << "1. Agregar Usuario\n";
        std::cout << "2. Modificar Usuario\n";
        std::cout << "3. Mostrar Todos los Usuarios\n";
        std::cout << "4. Buscar Usuario\n";
        std::cout << "0. Volver al Menú Principal\n";
        std::cout << "==============================================\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Opcion no valido\n";
            pausar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2:
                modificarUsuario();
                break;
            case 3:
                mostrarUsuarios();
                break;
            case 4:
                buscarUsuario();
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

void MenuUsuarios::agregarUsuario() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          AGREGAR USUARIO                     \n";
    std::cout << "==============================================\n";

    int cedula=solicitarEntero("cedula del usuario:");
    std::string nombreCompleto=solicitarTexto("nombre del usuario:");
    std::string accesoTexto = solicitarTexto("Esta activo? (s/n):"); //s de si, n de no
    bool estado =(accesoTexto =="s"  || accesoTexto =="S"); //minuscula o mayuscula de Si, si es alguna de esas se toma como true, sino es false

    try {
        Usuario* usuario=new Usuario(cedula, nombreCompleto, estado);
        gestor->agregarUsuario(usuario);
        std::cout<<"Usuario ha sido agregado\n";
    }catch (const std::exception &e) {
        std::cerr<<"Error al agregar el usuario:"<<e.what()<<std::endl;
    }

    pausar();
}


void MenuUsuarios::modificarUsuario() {
    limpiarPantalla();
    std::cout << "\n==================================================\n";
    std::cout << "          MODIFICAR USUARIO                   \n";
    std::cout << "==================================================\n";

    int cedula=solicitarEntero("Ingrese la cedula del usuario a modificar:");

    try {
        Usuario* usuario=gestor->buscarPorId(cedula);

        std::cout<<"Usuario encontrado\n";
        //se muestra la info del usuario encontrado
        std::cout<<"Cedula: "<<usuario->getCedula()<<"\n";
        std::cout<<"Nombre: "<<usuario->getNombreCompleto()<<"\n";
        std::cout<<"Estado: "<<usuario->getEstado()<<"\n";

        std::cout<<"Ingrese los nuevos datos para el usuario:\n";
        std::string nombreModificado=solicitarTexto("Nuevo nombre:");
        std::string accesoTexto = solicitarTexto("Nuevo estado: esta activo? (s/n):"); //s de si, n de no
        bool nuevoEstado =(accesoTexto =="s"  || accesoTexto =="S"); //minuscula o mayuscula de Si, si es alguna de esas se toma como true, sino es false

        Usuario* datosNuevos=new Usuario(cedula, nombreModificado, nuevoEstado);

        if (gestor->modificarUsuario(cedula, datosNuevos)) {
            std::cout<<"Usuario ha sido modificado\n";
        }else {
            std::cout<<"No se pudo modificar Usuario\n";
        }

        delete datosNuevos;

    }catch (const std::exception &e) {
        std::cerr<<"Error al modificar: "<<e.what()<<std::endl;
    }

    pausar();
}

void MenuUsuarios::mostrarUsuarios() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          LISTADO DE USUARIOS                 \n";
    std::cout << "==============================================\n";

    //hay que ver si hay usuarios
    if (gestor->get_lista_usuarios()->tamano() == 0) {
        std::cout<<"No hay usuarios agregados\n";
        pausar();
        return;
    }

    //mostrar los usuarios
    for (int i=0; i<gestor->get_lista_usuarios()->tamano(); i++) {
        Usuario* usuario=gestor->get_usuario(i);
        std::cout << "\n----- Usuario " << (i + 1) << " -----\n";
        std::cout << "Cédula: " << usuario->getCedula() << "\n";
        std::cout << "Nombre: " << usuario->getNombreCompleto() << "\n";
        std::cout << "Estado: " << usuario->getEstado() << "\n";
        std::cout << "---------------------\n";
    }

    pausar();
}

void MenuUsuarios::buscarUsuario() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          BUSCAR USUARIO                      \n";
    std::cout << "==============================================\n";

    int cedula=solicitarEntero("Ingrese la cedula del usuario q busca:");

    try {
        Usuario* usuario=gestor->buscarPorId(cedula);
        std::cout<<"Usuario encontrado\n";

        std::cout << "Cédula: " << usuario->getCedula() << "\n";
        std::cout << "Nombre: " << usuario->getNombreCompleto() << "\n";
        std::cout << "Estado: " << usuario->getEstado() << "\n";
    }catch (const std::exception &e) {
        std::cerr<<"Error al buscar: "<<e.what()<<std::endl;
    }

    pausar();
}
