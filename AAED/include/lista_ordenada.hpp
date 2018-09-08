#ifndef LISTA_ORDENADA_HPP
#define LISTA_ORDENADA_HPP
#include <iostream>
#include "lista.hpp"
template <typename T>
class Lista_O{
    public:
    typedef typename Lista<T>::posicion posicion;
    Lista_O() = default;
    void insertar(const T& x);
    void eliminar(posicion p){ L.eliminar(p); }
    const T& elemento(posicion p) const { return L.elemento(p); }
    T& elemento(posicion p){ return L.elemento(p); }
    posicion buscar(const T& x) const { return L.buscar(x); }
    posicion siguiente(posicion p) const { return L.siguiente(p); }
    posicion anterior(posicion p) const { return L.anterior(p); }
    posicion primera() const { return L.primera(); }
    posicion fin() const{ return L.fin(); }
    Lista<T> lista() const { return L; }
    private:
    Lista<T> L;
    posicion menor(const T& x);
};

template <typename T>
typename Lista_O<T>::posicion Lista_O<T>::menor(const T& x){
    posicion q = L.fin();
    bool insertado = false;
    for(posicion p = L.primera() ; p != L.fin() && !insertado ; p = L.siguiente(p) ){
        if (x < L.elemento(p)){
            q = p;
            insertado = true;
        }
    }
    return q;
}

template <typename T>
void Lista_O<T>::insertar(const T& x){
    L.insertar(x,menor(x));
}
#endif
