//
// Created by ugald on 24/4/2025.
//

#include "MenuReportes.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

MenuReportes::MenuReportes(GestorMateriales *materiales, GestorUsuarios *usuarios, GestorPrestamos *prestamos) :gestorMateriales(materiales), gestorUsuarios(usuarios), gestorPrestamos(prestamos) {
}
MenuReportes::~MenuReportes() {}

void MenuReportes::limpiarPantalla() {
    std::system("cls");
}
void MenuReportes::pausar() {
    std::cout<<"Presiones Enter para continuar: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
int MenuReportes::solicitarEntero(const std::string& mensaje) {
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
std::string MenuReportes::solicitarTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void MenuReportes::mostrarMenu() {
    int opcion;
    bool volver = false;

    while (!volver) {
        limpiarPantalla();
        std::cout << "\n==============================================\n";
        std::cout << "          REPORTES DEL SISTEMA                \n";
        std::cout << "==============================================\n";
        std::cout << "1. Reporte de Inventario de materiales\n";
        std::cout << "2. Reporte de Usuarios\n";
        std::cout << "3. Materiales en Prestamo\n";
        std::cout << "4. Usuarios con Prestamos Activos\n";
        std::cout << "0. Volver al Menu Principal\n";
        std::cout << "==============================================\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opción no válida\n";
            pausar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                reporteInventarioMateriales();
            break;
            case 2:
                reporteUsuarios();
            break;
            case 3:
                reporteMaterialesEnPrestamo();
            break;
            case 4:
                reportePrestamosPorUsuario();
            break;
            case 0:
                volver = true;
            break;
            default:
                std::cout << "Opcion no válida\n";
            pausar();
            break;
        }
    }
}

void MenuReportes::reporteMaterialesEnPrestamo() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "        MATERIALES EN PRESTAMO                \n";
    std::cout << "==============================================\n";

    //ver si hay prestamos agregados
    if (gestorPrestamos->get_lista_prestamos()->tamano() == 0) {
        std::cout<<"no hay prestamos agregados\n";
        pausar();
        return;
    }
// Opciones de reporte
    int opcionReporte;
    std::cout << "1. Reporte general de materiales en prestamo\n";
    std::cout << "2. Reporte por tipo de material\n";
    std::cout << "Seleccione una opcion: ";

    if (!(std::cin >> opcionReporte) || (opcionReporte != 1 && opcionReporte != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opción no valida\n";
        pausar();
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Si es reporte por tipo de material, solicitar el tipo
    std::string tipoMaterial = "";
    if (opcionReporte == 2) {
        std::string tipoMaterial;
        int opcion;

        std::cout << "\nTipos de material disponibles:\n";
        std::cout << "1. Libro\n";
        std::cout << "2. Revista\n";
        std::cout << "3. Artículo\n";
        std::cout << "4. Video\n";
        std::cout << "5. Digital\n";

        while (true) {
            opcion = solicitarEntero("Ingrese el número del tipo de material a buscar: ");

            switch (opcion) {
                case 1:
                    tipoMaterial = "Libro";
                    break;
                case 2:
                    tipoMaterial = "Revista";
                    break;
                case 3:
                    tipoMaterial = "Artículo";
                    break;
                case 4:
                    tipoMaterial = "Video";
                    break;
                case 5:
                    tipoMaterial = "Digital";
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo.\n";
                    pausar();
                    continue;
            }
            break;
        }
    }

    bool hayPrestamos = false;

    // Recorrer la lista de préstamos
    for (int i = 0; i < gestorPrestamos->get_lista_prestamos()->tamano(); i++) {
        Prestamo* prestamo = gestorPrestamos->get_lista_prestamos()->buscar(i)->getItem();

        // Verificar si el material está prestado y si cumple con el filtro de tipo (si aplica)
        if (prestamo->get_material()->get_estado_material() == "Prestado" &&
            (opcionReporte == 1 ||
             prestamo->get_material()->get_tipo_material() == tipoMaterial)) {

            if (!hayPrestamos) {
                if (opcionReporte == 1) {
                    std::cout << "Lista de materiales en Prestamo\n";
                } else {
                    std::cout << "Lista de materiales en Prestamo de tipo: '" << tipoMaterial << "'\n";
                }
                std::cout << "-------------------------------\n";
                hayPrestamos = true;
            }

            // Mostrar la info de los materiales prestados
            std::cout << "\n----- Material " << (i + 1) << " -----\n";
            std::cout << "Titulo: " << prestamo->get_material()->get_titulo() << "\n";
            std::cout << "Clasificacion: " << prestamo->get_material()->get_num_clasificacion() << "\n";
            std::cout << "Tipo: " << prestamo->get_material()->get_tipo_material() << "\n";
            std::cout << "Prestado a: " << prestamo->get_usuario()->getNombreCompleto() << "\n";
            std::cout << "Cedula: " << prestamo->get_usuario()->getCedula() << "\n";
            std::cout << "Fecha de Préstamo: " << prestamo->get_fecha_prestamo() << "\n";
            std::cout << "Fecha de devolución: " << prestamo->get_fecha_devolucion() << "\n";
        }
    }

    if (!hayPrestamos) {
        if (opcionReporte == 1) {
            std::cout << "No hay materiales en préstamo\n";
        } else {
            std::cout << "No hay materiales de tipo '" << tipoMaterial << "' en préstamo\n";
        }
    }
    pausar();
}



void MenuReportes::reportePrestamosPorUsuario() {
limpiarPantalla();

    //ver si hay usuarios
    if (gestorUsuarios->get_lista_usuarios()->tamano() == 0) {
        std::cout<<"no hay usuarios agregados\n";
        pausar();
        return;
    }

    //ver si hay prestamos
    if (gestorPrestamos->get_lista_prestamos()->tamano() == 0) {
        std::cout<<"no hay prestamos agregados\n";
        pausar();
        return;
    }

    int idUsuario=solicitarEntero("Ingrese el id del usuario:");

    try {
        Usuario* usuario=gestorUsuarios->buscarPorId(idUsuario);

        //mostrar info del usuario
        std::cout<<"Usuario: "<<usuario->getNombreCompleto()<<"\n";
        std::cout<<"Cedula: "<<usuario->getCedula()<<"\n";
        std::cout<<"Estado: "<<usuario->getEstado()<<"\n";

        //lista de los materiales prestados del usuario
        bool prestado=false;
        std::cout<<"Materiales en Prestamo\n";
        for (int j=0; j<gestorPrestamos->get_lista_prestamos()->tamano(); j++) {
            Prestamo* prestamo=gestorPrestamos->get_lista_prestamos()->buscar(j)->getItem();
            //condicional para ver si el id del prestamo y del usuario ingresado coinciden
            if (prestamo->get_usuario()->getCedula() == usuario->getCedula() && prestamo->get_material()->get_estado_material() == "Prestado") {
                prestado=true;
                std::cout<<prestamo->get_material()->get_titulo()<<"\n";
                std::cout<<"Clasificacion: "<<prestamo->get_material()->get_num_clasificacion()<<"\n";
                std::cout<<"Fecha de devolucion: "<<prestamo->get_fecha_devolucion()<<"\n";
            }
        }

        if (!prestado) {
            std::cout<<"Este usuario no tiene prestamos activos\n";
        }


    }catch (const UsuarioNoencontrado& e) {
        std::cerr<<"Error: "<<e.what()<<"\n";
    }catch (const std::exception& e) {
        std::cerr<<"Error: "<<e.what()<<"\n";
    }

    pausar();
}

void MenuReportes::reporteInventarioMateriales() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "       REPORTE DE INVENTARIO DE MATERIALES    \n";
    std::cout << "==============================================\n";

    // ver si hay materiales
    if (gestorMateriales->get_lista_materiales()->tamano() == 0) {
        std::cout << "No hay materiales agregados\n";
        pausar();
        return;
    }

    // Mostrar los materiales
    for (int i = 0; i < gestorMateriales->get_lista_materiales()->tamano(); i++) {
        Material* material = gestorMateriales->obtener_material(i);
        std::cout << "\n----- Material " << (i + 1) << " -----\n";
        std::cout << material->imprimir();
        std::cout << "-----------------\n";
    }

    pausar();
}

void MenuReportes::reporteUsuarios() {
    limpiarPantalla();
    std::cout << "\n==============================================\n";
    std::cout << "          REPORTE DE USUARIOS                 \n";
    std::cout << "==============================================\n";

    // ver si hay usuarios
    if (gestorUsuarios->get_lista_usuarios()->tamano() == 0) {
        std::cout << "No hay usuarios agregados\n";
        pausar();
        return;
    }

    // Mostrar los usuarios
    for (int i = 0; i < gestorUsuarios->get_lista_usuarios()->tamano(); i++) {
        Usuario* usuario = gestorUsuarios->get_usuario(i);
        std::cout << "\n----- Usuario " << (i + 1) << " -----\n";
        std::cout << "Cedula: " << usuario->getCedula() << "\n";
        std::cout << "Nombre: " << usuario->getNombreCompleto() << "\n";
        std::cout << "Estado: " << usuario->getEstado() << "\n";
        std::cout << "---------------------\n";
    }

    pausar();
}
