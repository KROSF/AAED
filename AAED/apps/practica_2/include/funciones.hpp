#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

const int _10M_ = 10000000;
//* Ejercicio 1
/**
 * @brief Genera un número pseudoaleatorio entero 
 *        en el intervalo discreto [a, b].
 * @param min Minimo número en el intervalo.
 * @param max Maximo número en el intervalo.
 * @return int Número genereado que pertenece al intervalo
 */
inline int rand_min_max_discreto(int min, int max){
    return ((rand() % max) + min);
}

//* Ejercicio 2
/**
 * @brief  Simula las tiradas de un dado e imprime las frecuencias relativas.
 * 
 * @param n umero de veces que se a de tirar el dado.
 * @return std::vector<double> Vector con el numero de veces de cada cara del dado.
 */
std::vector<double> simular_dado(double n){
    std::vector<double> v = {0,0,0,0,0,0};
    for(int i  = 0; i < n; ++i)
        ++v[rand_min_max_discreto(1,6) - 1];
    return v;
}

//* Ejercicio 3
/**
 * @brief Genera un número pseudoaleatorio en coma flotante 
 *        en el intervalo continuo [a, b].
 * @param min Minimo número en el intervalo.
 * @param max Maximo número en el intervalo.
 * @return double Número genereado que pertenece al intervalo.
 */
inline double rand_min_max_continuo(double min, double max){
    return ((double)rand()) / ((double)RAND_MAX) * max + min;
}

//* Ejercicio 4
/**
 * @brief Calcula la media un intervalo continuo para y = 4 * √(1 - x^2)
 *        donde x = rand_min_max_continuo(min,max).
 * @param min Minimo número en el intervalo.
 * @param max Maximo número en el intervalo.
 * @param size Tamaño de la prueba.
 * @return double Media.
 */
double media_intervalo_continuo(double min, double max, int size){
    double sum{0};
    for (int i = 0; i < size; ++i)
        sum += 4 * std::sqrt(1 - std::pow(rand_min_max_continuo(min,max),2));
    return sum/size;
}

//* Ejercicio 5
/**
 * @brief Calcula las permutaciones de los seis primeros números naturales.
 * 
 * @param n Numero de permutaciones a generar.
 * @return int Numero de permutaciones ordenadas.
 */
int permutaciones(int n){
    std::vector<int> ordenado{0,1,2,3,4,5}, permutable{0,1,2,3,4,5};
    int c = 0;
    for (int i = 0; i < n; ++i){
        std::next_permutation(permutable.begin(),permutable.end());
        if ( permutable == ordenado )
            ++c;
    }
    return c;
}
#endif
