#ifndef OPERACIONES_HPP
#define OPERACIONES_HPP
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Polinomio{
public:
    explicit Polinomio(unsigned grd):data(std::vector<double>(grd+1)),grado_(grd){}
    explicit Polinomio(std::string str,unsigned grd);
    unsigned grado() const { return grado_; }
    double coeficiente(unsigned grd) const{
        return (grd > grado_) ? 0.0 : data[grd];
    }
    void coeficiente(unsigned grd , double coef){
        assert(grd<=grado_);
        data[grd] = coef;
    }
    std::string to_string() const;

private:
    std::vector<double> data;
    unsigned grado_;
};

Polinomio operator + (const Polinomio& primero, const Polinomio & segundo);
Polinomio operator - (const Polinomio& primero, const Polinomio & segundo);
Polinomio operator * (const Polinomio& primero, const Polinomio & segundo);
Polinomio derivada( const Polinomio& pol);
std::ostream& operator << (std::ostream & os,const Polinomio& pol);
#endif
