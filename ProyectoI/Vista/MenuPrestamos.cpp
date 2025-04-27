//
// Created by ugald on 24/4/2025.
//

#include "MenuPrestamos.h"
#include "../Modelo/Prestamo.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

MenuPrestamos::MenuPrestamos(GestorPrestamos* prestamos, GestorMateriales* materiales, GestorUsuarios* usuarios)
    : gestorPrestamos(prestamos), gestorMateriales(materiales), gestorUsuarios(usuarios) {}

MenuPrestamos::~MenuPrestamos() {}

void MenuPrestamos::limpiarPantalla() {
    std::system("cls");
}

void MenuPrestamos::pausar() {
    std::cout << "Presione Enter para continuar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int MenuPrestamos::solicitarEntero(const std::string &mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Error: Ingrese un numero entero valido\n";
        }
    }
}

std::string MenuPrestamos::solicitarTexto(const std::string &mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void MenuPrestamos::mostrarMenu() {
    int opcion;
    bool volver=false;

    while (!volver) {
        limpiarPantalla();
        std::cout << "\n==============================================\n";
        std::cout << "          GESTIÓN DE PRÉSTAMOS                \n";
        std::cout << "==============================================\n";
        std::cout << "1. Registrar Préstamo\n";
        std::cout << "2. Registrar Devolución\n";
        std::cout << "3. Mostrar Préstamos Activos\n";
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
                registrarPrestamo();
                break;
            case 2:
                registrarDevolucion();
                break;
            case 3:
                mostrarPrestamos();
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
std::string MenuPrestamos::obtenerFechaActual() {
    std::time_t t=std::time(nullptr);
    std::tm* ahora=std::localtime(&t);

    std::stringstream ss;
    ss<<std::setw(2)<<std::setfill('0')<<ahora->tm_mon<<"/"
      <<std::setw(2)<<std::setfill('0')<<(ahora->tm_mon+1)<<"/"
      <<(ahora->tm_year+1900);
//devuelve la fecha en dia/mes/anio
    return ss.str();
}

std::string MenuPrestamos::calcularFechaDevolucion(Material *material) {
    std::time_t t=std::time(nullptr);
    std::tm* ahora=std::localtime(&t);
    std::tm fechaDevolucion=*ahora;

    //devuelve el periodo permitido segun el material q es
    if (dynamic_cast<Libro*>(material)) {
        //libros se dan maximo una semana
        fechaDevolucion.tm_mday += 7;
    }else if (dynamic_cast<Revista*>(material)) {
        //revistra se da por 2 dias
        fechaDevolucion.tm_mday += 2;
    }else if (dynamic_cast<MaterialDigital*>(material)) {
        //material digital se presta por hasta 5 dias
        fechaDevolucion.tm_mday += 5;
    }else {
        fechaDevolucion.tm_mday += 5; //cantidad predeterminada de dia supongo q 5 por poner
    }

    std::mktime(&fechaDevolucion);//segun vi mktime ajusta meses anios y dias automaticamente

    std::stringstream ss;
    ss<<std::setw(2)<<std::setfill('0')<<fechaDevolucion.tm_mday<<"/"
      <<std::setw(2)<<std::setfill('0')<<(fechaDevolucion.tm_mon+1)<<"/"
      <<(fechaDevolucion.tm_year+1900);
    //devuelve la fecha en dia/mes/anio
    return ss.str();
}


void MenuPrestamos::registrarPrestamo() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          REGISTRAR PRÉSTAMO                  \n";
    std::cout << "==============================================\n";
//primero verificaiciones
//luego obtener la fecha y mostrar la info del prestamo
//pedir al usuario confirmar el prestamo y crearlo en caso de
//cambiar el estado del material a Prestado IMPORTANTE


    //ver si hay materiales agregados
    if (gestorMateriales->get_lista_materiales()->tamano() == 0) {
        std::cout<<"no hay materiales agregados\n";
        pausar();
        return;
    }
    //ver si hay usuarios agregados
    if (gestorUsuarios->get_lista_usuarios()->tamano() == 0) {
        std::cout<<"no hay usuarios agregados\n";
        pausar();
        return;
    }

    int idUsuario=solicitarEntero("Ingrese la cedula del usuario:");//usuario a poner prestamo

    //se crea un usuario para tenerlo a mano y buscar
    Usuario* usuario=nullptr;
    try {
        usuario=gestorUsuarios->buscarPorId(idUsuario);

        if (!usuario->getEstado()) {
            std::cout<<"El usuario no esta activo entonces no puede tener prestamos\n";
            pausar();
            return;
        }

        std::cout<<"Usuario encontrado: "<<usuario->getNombreCompleto()<<std::endl;
    }catch (const std::exception& e) {
        std::cerr<<"Error en prestamo: "<<e.what()<<std::endl;
        pausar();
        return;
    }

    //numero de clas de material
    int numClasificacion=solicitarEntero("Ingrese el numero de clasificacion del material:");

    //se crea un material para tenerlo a mano y buscarlo
    Material* material=nullptr;
    try {
        material=gestorMateriales->buscarMaterialPorClasificacion(numClasificacion);

        //ver si esta disponible
        if (material->get_estado_material() != "Disponible") {
            std::cout<<"El material no esta disponible\n";
            pausar();
            return;
        }

        std::cout<<"Material encontrado"<<material->get_titulo()<<"\n";

    }catch (const std::exception& e) {
        std::cerr<<"Error en prestamo: "<<e.what()<<std::endl;
        pausar();
        return;
    }

//fecha
    std::string fechaPrestamo=obtenerFechaActual();
    std::string fechaDevolucion=calcularFechaDevolucion(material);


    //mostrar la info del prestamo
    std::cout << "\nDetalles del préstamo:\n";
    std::cout<<"Usuario: "<<usuario->getNombreCompleto()<<" Cedula: "<<usuario->getCedula()<<"\n";
    std::cout<<"Material: "<<material->get_titulo()<<" Clasificacion: "<<material->get_num_clasificacion()<<"\n";
    std::cout<<"Fecha de prestamo: "<<fechaPrestamo<<"\n";
    std::cout<<"Fecha de devolucion: "<<fechaDevolucion<<"\n";

    //preguntar si confirma el prestamo
    std::string confirmar=solicitarTexto("Confirma prestamo? (s/n):");

    if (confirmar == "s" || confirmar == "S") { //si es si en mayuscula o minuscula da true, sino false
        //se crea el prestamo
        Prestamo* nuevoPrestamo=new Prestamo(*usuario, *material, fechaPrestamo, fechaDevolucion);

        //se agrega el prestamo
        gestorPrestamos->agregarPrestamo(nuevoPrestamo);

        //actualiza el estado del material
        material->set_estado_material("Prestado");

        std::cout<<"Prestamo ha sido registrado\n";
    }else {
        std::cout<<"prestamo cancelado\n";
    }

    pausar();
}

void MenuPrestamos::registrarDevolucion() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          REGISTRAR DEVOLUCIÓN                \n";
    std::cout << "==============================================\n";

    //ver si hay prestamos
    if (gestorPrestamos->get_lista_prestamos()->tamano() == 0) {
        std::cout<<"no hay prestamos agregados\n";
        pausar();
        return;
    }

    //numero de Clas de material a devolver
    int numClasificacion=solicitarEntero("Ingrese el numero de clasificacion del material a devolver:");

    //se crea un prestamo para tenerlo a mano y buscarlo
    Prestamo* prestamo=nullptr;
    int indicePrestamo=0;

    //se va a recorrer la lista de prestamos del gestor hasta encontrar q cuadren el numClasificacion y q este activo
    for (int i=0; i<gestorPrestamos->get_lista_prestamos()->tamano(); i++) {
        Prestamo* p=gestorPrestamos->get_lista_prestamos()->buscar(i)->getItem();
        if (p->get_material()->get_num_clasificacion() == numClasificacion && p->get_material()->get_estado_material() == "Prestado") {
            prestamo=p;
            indicePrestamo=i;
            break;
        }
    }

    //si en el recorrido anterior no encontro nada la variable prestamo queda como nullptr como se instancio
    //tambien sirve para verificar para mas abajo no llamar metodos de un objeto nullptr
    if (prestamo == nullptr) {
        std::cout<<"no se encontro un prestamo activo con ese numero de clasificacion\n";
        pausar();
        return;
    }

    //se crea un material para tenerlo a mano y buscarlo
    Material* material=nullptr;
    //se crea un usuario para tenerlo a mano y buscarlo
    Usuario* usuario=nullptr;

    try {
        material=gestorMateriales->buscarMaterialPorClasificacion(numClasificacion);
        usuario=gestorUsuarios->buscarPorId(prestamo->get_usuario()->getCedula());

        //mostrar la info del prestamo
        std::cout << "\nDetalles del préstamo a devolver:\n";
        std::cout<<"Usuario: "<<usuario->getNombreCompleto()<<" Cedula: "<<usuario->getCedula()<<"\n";
        std::cout<<"Material: "<<material->get_titulo()<<" Clasificacion: "<<material->get_num_clasificacion()<<"\n";
        std::cout<<"Fecha de prestamo: "<<prestamo->get_fecha_prestamo()<<"\n";
        std::cout<<"Fecha de devolucion: "<<prestamo->get_fecha_devolucion()<<"\n";

        //confirmar devolucion
        std::string confirmar=solicitarTexto("Confirma la devolucion del prestamo? (s/n):");
        if (confirmar == "s" || confirmar == "S") {
            //actualiza estado del prestamo
            prestamo->get_material()->set_estado_material("Disponible");

            std::cout<<"Devolucion registrada\n";
        }else {
            std::cout<<"Devolucion cancelada\n";
        }

    }catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    pausar();
}


void MenuPrestamos::mostrarPrestamos() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          MOSTRAR PRÉSTAMOS                   \n";
    std::cout << "==============================================\n";

    //ver si hay prestamos agregados
    if (gestorPrestamos->get_lista_prestamos()->tamano() == 0) {
        std::cout<<"no hay prestamos agregados\n";
        pausar();
        return;
    }

    //mostrar los prestamos
    for (int i=0; i<gestorPrestamos->get_lista_prestamos()->tamano(); i++) {
        Prestamo* prestamo=gestorPrestamos->get_lista_prestamos()->buscar(i)->getItem();

        std::cout<<"\n----- Préstamo " << (i + 1) << " -----\n";
        std::cout<<"Material: "<<prestamo->get_material()->getTipo()<<"\n";
        std::cout<<"Usuario: "<<prestamo->get_usuario()->getNombreCompleto()<<"\n";
        std::cout<<"Fecha de prestamo: "<<prestamo->get_fecha_prestamo()<<"\n";
        std::cout<<"Fecha de devolucion: "<<prestamo->get_fecha_devolucion()<<"\n";
        std::cout<<"Material: "<<prestamo->get_material()->get_estado_material()<<"\n";


    }

    pausar();
}

