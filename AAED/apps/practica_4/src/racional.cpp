#include <cstdlib>
#include <cassert>
#include <math/racional.hpp>

long Racional::mcd(long x, long y){
    long a;
    // Algoritmo de Euclides
    if (x < y) {
            a = x;
            x = y;
            y = a;
    }
    while ((a = x % y)) {
            x = y;
            y = a;
    }
    return y;
}

inline long Racional::mcm(long x, long y){
    return x / mcd(x,y) * y;
}

Racional::Racional(long n,long d):n_(n),d_(d){
    assert(d != 0); // Verificar precondición
    if (n == 0)
        d = 1;
    else {
        if (d < 0) { // Poner signo en el numerador
            n = -n;
            d = -d;
        }
        // Reducir fracción
        long m = mcd(abs(n), d);
        if (m != 1) {
            n /= m;
            d /= m;
        }
    }
}

Racional Racional::operator-() const{
    Racional s; // racional 0/1
    if (n_ != 0) {
        s.n_ = -n_;
        s.d_ = d_;
    }
    return s;
}
Racional inv(const Racional& r){
    Racional s;
    assert(r.n_ != 0); // Verificar precondición
    if (r.n_ > 0) {
        s.n_ = r.d_;
        s.d_ = r.n_;
    }
    else { // Poner signo en el numerador
        s.n_ = -r.d_;
        s.d_ = -r.n_;
    }
    return s;
}
Racional& Racional::operator+=(const Racional& s){
    long m = Racional::mcd(this->d_, s.d_);
    Racional tmp(s.d_ / m * this->n_ + this->d_ / m * s.n_,
                                                Racional::mcm(this->d_, s.d_));
    this->n_ =  tmp.n_;
    this->d_ =  tmp.d_;
    return *this;
}
Racional& Racional::operator-=(const Racional& r){
    return *this += (-r);
}
Racional& Racional::operator*=(const Racional& s){
    if (this->n_ && s.n_) {
        long a = Racional::mcd(abs(this->n_), s.d_);
        long b = Racional::mcd(this->d_, abs(s.n_));
        this->n_ = (this->n_ / a) * (s.n_ / b);
        this->d_ = (this->d_ / b) * (s.d_ / a);
    }
    return *this;
}
Racional& Racional::operator/=(const Racional& r){
    return *this *= inv(r);
}
Racional operator + (const Racional& r, const Racional& s){
    return Racional(r) += s;
}
Racional operator - (const Racional& r, const Racional& s){
    return Racional(r) -= s;
}
Racional operator * (const Racional& r, const Racional& s){
    return Racional(r) *= s;
}
Racional operator / (const Racional& r, const Racional& s){
    return Racional(r) /= s;
}

bool operator < (const Racional& r, const Racional& s){
    return Racional(r + -s).num() < 0;
}

bool operator > (const Racional& r, const Racional& s){
    return s < r;
}

bool operator == (const Racional& r, const Racional& s){
    return r.den() == s.den() && r.num() == s.num();
}

bool operator != (const Racional& r, const Racional& s){
    return !(r == s);
}

bool operator <= (const Racional& r, const Racional& s){
    return r < s || r == s;
}
bool operator >= (const Racional& r, const Racional& s){
    return r > s || r == s;
}
