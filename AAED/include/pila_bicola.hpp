#ifndef PILA_BICOLA_HPP
#define PILA_BICOLA_HPP
#include "bicola.hpp"
template <typename T>
class Pila{
public:
    bool vacia() const { return bc.vacia(); };
    T tope() const { return bc.back(); }
    void pop() { bc.pop_back(); }
    void push(const T& x) { bc.push_back(x); }
private:
    Bicola<T> bc;
};
#endif
