#include <math/polinomio.hpp>

Polinomio::Polinomio(std::string str,unsigned grd):data(std::vector<double>(grd+1)),grado_(grd){
    double coef;
    unsigned grds;
    size_t pos = 0;
    std::string::size_type sz;
    while((pos = str.find('+')) != std::string::npos){
        sscanf(str.substr(0, pos).c_str(),"%lfx^%d",&coef,&grds);
        data[grds] = coef;
        str.erase(0, pos + 1);
    }
    data[0] = std::stod (str,&sz);
}

Polinomio operator + (const Polinomio& primero, const Polinomio & segundo){

    unsigned max = std::max(primero.grado(),segundo.grado());
    Polinomio suma(max);
    for (unsigned i = 0; i <= max ; ++i){
        suma.coeficiente(i, primero.coeficiente(i)+segundo.coeficiente(i));
    }
    return suma;
}
Polinomio operator - (const Polinomio& primero, const Polinomio & segundo){
    unsigned max = std::max(primero.grado(),segundo.grado());
    Polinomio resta(max);
    for (unsigned i = 0; i <= max ; ++i){
        resta.coeficiente(i, primero.coeficiente(i)-segundo.coeficiente(i));
    }
    return resta;
}
Polinomio operator * (const Polinomio& primero, const Polinomio & segundo){

    Polinomio mul(primero.grado() + segundo.grado());
    for(unsigned i = 0 ; i <= primero.grado();++i)
        for(unsigned j = 0 ; j <= segundo.grado();++j)
            mul.coeficiente(i+j,mul.coeficiente(i+j)+primero.coeficiente(i)*segundo.coeficiente(j));
    return mul;
}

Polinomio derivada( const Polinomio& pol){
    Polinomio derivada(pol.grado()-1);
    for(unsigned i = pol.grado() ;i >= 1;--i)
        derivada.coeficiente(i-1,i*pol.coeficiente(i));
    return derivada;
}

std::string Polinomio::to_string() const{
    std:: string os;
    for(unsigned i = grado() ; i >= 1;--i){
        if(coeficiente(i) != 0){
            if (i > 1)
                os += std::to_string((int)coeficiente(i)) + "x^" + std::to_string(i)+ " + ";
            else if ( i > 0 )
                    os += std::to_string((int)coeficiente(i)) + "x";
        }
    }
    if(coeficiente(0) != 0)
        os += " + " + std::to_string((int)coeficiente(0));
    return os;
}

std::ostream& operator << (std::ostream & os,const Polinomio& pol){
    return os << pol.to_string();
}