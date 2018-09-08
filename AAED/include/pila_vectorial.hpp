#ifndef PILA_VECTORIAL_HPP
#define PILA_VECTORIAL_HPP
#include <cassert>
#include <iostream>
template <typename T>
class Pila {
 	public:
 		explicit Pila(unsigned TamaMax); // constructor
 		Pila(const Pila& p); // ctor. de copia
 		Pila& operator =(const Pila& p); // asignación entre pilas
                bool vacia() const;
                bool llena() const; // Requerida por la implementación
                T tope() const;
                void pop();
                void push(const T& x);
                ~Pila(); // destructor
        private:
                T *elementos; // vector de elementos
                unsigned Lmax; // tamaño del vector
                int tope_; // posición del tope
 };

template <typename T>
inline Pila<T>::Pila(unsigned TamaMax) : elementos(new T[TamaMax]), Lmax(TamaMax),tope_(-1) {}

template <typename T>
Pila<T>::Pila(const Pila<T>& p) : elementos(new T[p.Lmax]),Lmax(p.Lmax),tope_(p.tope_){
        for (int i = 0; i <= tope_; i++) // copiar el vector
                elementos[i] = p.elementos[i];
}

template <typename T>
Pila<T>& Pila<T>::operator =(const Pila < T>& p){
        if (this != &p) { // evitar autoasignación
                // Destruir el vector y crear uno nuevo si es necesario
                if (Lmax != p.Lmax) {
                        delete[] elementos;
                        Lmax = p.Lmax;
                        elementos = new T[Lmax];
                }
 		// Copiar el vector
 		tope_ = p.tope_;
 		for (int i = 0; i <= tope_; i++)
 			elementos[i] = p.elementos[i];
 	}
 	return *this;
 }

template <typename T>
inline bool Pila<T>::vacia() const{ return (tope_ == -1); }

template <typename T>
inline bool Pila<T>::llena() const{ return (tope_ != -1 && tope_ > (int)Lmax - 2); }

template <typename T>
inline T Pila<T>::tope() const{
        assert(!vacia());
        return elementos[tope_];
}

template <typename T>
inline void Pila<T>::pop(){
        assert(!vacia());
        --tope_;
}

template <typename T>
inline void Pila<T>::push(const T& x){
        assert(!llena());
        ++tope_;
        elementos[tope_] = x;
}

template <typename T>
inline Pila<T>::~Pila(){
        delete[] elementos;
}

template <typename T>
std::ostream& operator << (std::ostream& os,Pila<T> p){
        while(!p.vacia()){
                os << p.tope();
                p.pop();
        }
        return os;
}

#endif
