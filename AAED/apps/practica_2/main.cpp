#include "funciones.hpp"

//? Constate para el numero de iteraciones.
const int _10M_ = 10000000;

using std::cout;
using std::endl;

int main(void){
    //* Ejercicio 2
    std::vector<double> tiradas_dado = simular_dado(_10M_);
    cout << "Frecuencias absolutas para: " << _10M_ << " de tiradas." << endl;
    for (int i = 0; i < tiradas_dado.size(); ++i )
        cout << i+1 << ": " << tiradas_dado[i]/_10M_ << endl;

    //* Ejercicio 4
    cout << endl << "Media en el intervalo continuo [0,1] y " << _10M_ 
        << " de iteraciones."<< endl;
    cout << media_intervalo_continuo(0,1,_10M_) << endl;

    //* Ejercicio 5
    cout << endl << "Permutaciones ordenadas en " << _10M_ << " de permutaciones." << endl;
    cout << permutaciones(_10M_) << endl; 
}