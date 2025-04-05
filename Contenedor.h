#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <iostream>
#include "Nodo.h"
#include <sstream>
using namespace std;

template<class T>
class Contenedor {
private:
    Nodo<T> *inicio;
public:
    Contenedor(Nodo<T>* = nullptr);
    ~Contenedor();

    void agregarPrincipio(Nodo<T>*);
    void agregarFinal(Nodo<T>*);
    Nodo<T>* getInicio();
    bool existe(Nodo<T>*);
    void eliminar(int);
    void eliminar(Nodo<T>*);

    string toString();
};


template<class T>
Contenedor<T>::Contenedor(Nodo<T> *i) {
    inicio = i;
}

template<class T>
Contenedor<T>::~Contenedor() {
    Nodo<T> *aux = inicio;
    while (aux != nullptr) {
        Nodo<T> *aBorrar = aux;
        aux = aux->sig;
        delete aBorrar;
    }
    delete inicio;
}

template<class T>
void Contenedor<T>::agregarPrincipio(Nodo<T> *n) {
    if (inicio != nullptr) {
        n->setSig(inicio);
    }
    inicio = n;
}

template<class T>
void Contenedor<T>::agregarFinal(Nodo<T> *n) {
    Nodo<T> *aux = inicio;
    if (aux != nullptr) {
        while (aux->getSig() != nullptr) {

            aux = aux ->getSig();
        }
        aux->setSig(n);
    }
}

template<class T>
Nodo<T> * Contenedor<T>::getInicio() {
    return inicio;
}

template<class T>
bool Contenedor<T>::existe(Nodo<T> *n) {
    Nodo<T> *aux = inicio;
}

template<class T>
void Contenedor<T>::eliminar(int i) {
    int index = 0;
    Nodo<T> *aux = inicio;
    while (aux != nullptr && index < i - 1) {
        aux = aux->getSig();
        index ++;
    }
    if (aux != nullptr && aux->getSig() != nullptr) {
        Nodo<T> *aBorrar = aux->getSig();
        aux->setSig(aux->getSig()->getSig());
        delete aBorrar;
    }
}

template<class T>
void Contenedor<T>::eliminar(Nodo<T> *n) {
    Nodo<T> *aux = inicio;
    while (aux != nullptr && n != aux->getSig()) {
        aux = aux->getSig();
    }
    if (aux != nullptr && aux->getSig() != nullptr) {
        Nodo<T> *aBorrar = aux->getSig();
        aux->setSig(aux->getSig()->getSig());
        delete aBorrar;
    }
}

template<class T>
string Contenedor<T>::toString() {
    Nodo<T> *aux = inicio;
    stringstream ss;
    while (aux != nullptr) {
        ss << aux->getItem() << endl;
        aux = aux->getSig();
    }
    return ss.str();
}
#endif
