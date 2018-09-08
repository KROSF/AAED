#include <iostream>
#include <sort/cronometro.hpp>
#include <sort/sorting.hpp>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

void test_permutation(void(*ordenar)(vector<int>&),const std::string& algoritmo){
    vector<int> permutable = {0}, ordenable;
    cronometro crono;
    crono.activar();
    for (int i = 1; i < 10; ++i){
        do{
            ordenable = permutable;
            ordenar(ordenable);
        }while(std::next_permutation(permutable.begin(),permutable.end()));
        permutable.push_back(i);
    }
    crono.parar();
    std::cout << "Tiempo " << algoritmo <<": " << crono.tiempo() << std::endl;
}

void test_random_permutation(void(*ordenar)(vector<int>&),const std::string& algoritmo,int min =1000 ,int max = 20000 ,int incr = 1000){
    vector<int> v;
    cronometro crono;
    std::cout << cyan <<"Tiempos algoritmo: " << algoritmo << reset << std::endl << std::endl;
    for (int i = min; i <= max; i+= incr ){
        generate_vector(v,incr);
        std::random_shuffle (v.begin(), v.end());
        crono.activar();
        ordenar(v);
        crono.parar();
        std::cout << i << " " << crono.tiempo() << std::endl;
    }
    std::cout << std::endl;
}

int main(void){
    std::cout << green << "\nTest permutaciones\n" << reset << std::endl;
    test_permutation(bubble_sort,"burbuja");
    test_permutation(insertion_sort,"insercion");
    test_permutation(selection_sort,"seleccion");
    std::cout << green << "\nTest permutaciones aleatorias\n" << reset << std::endl;
    test_random_permutation(bubble_sort,"burbuja");
    test_random_permutation(insertion_sort,"insercion");
    test_random_permutation(selection_sort,"seleccion");
}

