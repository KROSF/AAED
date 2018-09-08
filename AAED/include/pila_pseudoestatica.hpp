#ifndef PILA_PSEUDOESTATICA_HPP
#define PILA_PSEUDOESTATICA_HPP
#include<iostream>
template <typename T>
class Pila_P{
public:
    explicit Pila_P(unsigned T_max):eltos(new T[T_max]),Lmax(T_max),tope_(-1){}
    Pila_P(const Pila_P& p):eltos(new T[p.Lmax]),Lmax(p.Lmax),tope_(p.tope_){
        for (int i = 0; i <= tope_; i++) // copiar el vector
            eltos[i] = p.eltos[i];
    }
    Pila_P& operator =(const Pila_P& p);
    bool vacia() const { return tope_ == -1;}
    bool llena() const { return (tope_ != -1 && tope_ > Lmax - 2); }
    const T& tope() const{
        assert(!vacia());
        return eltos[tope_];
    }
    void pop(){
        assert(!vacia());
        --tope_;
    }
    void push(const T& e){
        assert(!llena());
        ++tope_;
        eltos[tope_] = e;
    }
    ~Pila_P(){ delete[] eltos; }
private:
    T *eltos; // vector de elementos
    unsigned Lmax; // tamaño del vector
    int tope_; // posición del tope
};

template <typename T>
Pila_P<T>& Pila_P<T>::operator = (const Pila_P<T>& p){
    if (this != &p){ // evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != p.Lmax){
            delete[] eltos;
            Lmax = p.Lmax;
            eltos = new T[Lmax];
        }
        // Copiar el vector
        tope_ = p.tope_;
        for (int i = 0; i <= tope_; i++)
            eltos[i] = p.eltos[i];
    }
    return *this;
}

template <typename T>
std::ostream& operator << (std::ostream& os,Pila_P<T> p){
    while(!p.vacia()){
        os << p.tope();
        p.pop();
    }
    return os;
}

#endif
