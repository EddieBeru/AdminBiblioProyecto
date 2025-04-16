
#ifndef NODO_H
#define NODO_H
#include <ostream>


template <class T>
class Nodo {
private:
    T* item;
    Nodo<T>* sig;
public:
    Nodo(T* = nullptr, Nodo<T>* = nullptr);
    ~Nodo();
    T getItem();
    void setItem(T*);
    Nodo<T>* getSig();
    void setSig(Nodo<T>*);

    friend std::ostream & operator<<(std::ostream &os, const Nodo &obj) {
        return os << obj.item;
    }
};


template<class T>
Nodo<T>::Nodo(T* i , Nodo<T> *s) {
    item = i;
    sig = s;
}

template<class T>
Nodo<T>::~Nodo() {
}

template<class T>
T Nodo<T>::getItem() {
    return item;
}

template<class T>
void Nodo<T>::setItem(T* i) {
    item = i;
}

template<class T>
Nodo<T> * Nodo<T>::getSig() {
    return sig;
}

template<class T>
void Nodo<T>::setSig(Nodo<T> *s) {
    sig = s;
}
#endif //NODO_H