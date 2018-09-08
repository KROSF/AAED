
#ifndef COLA_BICOLA_HPP
#define COLA_BICOLA_HPP
#include "bicola.hpp"
template <typename T>
class Cola{
public:
    bool vacia() const { return bc.vacia(); }
    const T& frente() const { return bc.front(); }
    void pop() { bc.pop_front(); }
    void push(const T& x){ bc.push_back(x); }
private:
    Bicola<T> bc;
};
#endif
