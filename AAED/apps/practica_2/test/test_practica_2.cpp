#include <gtest/gtest.h>
#include "../include/funciones.hpp"

TEST(practica_2,rango_intervalo_discreto){
    auto val = rand_min_max_discreto(1,10);
    EXPECT_TRUE((val >= 1) && (val <= 10));
}

TEST(practica_2,simular_dado){
    std::vector<double> v = simular_dado(_10M_);
    double sum = 0;
    for(auto& e : v){
        e /= _10M_;
        sum+=e;
    }
    ASSERT_DOUBLE_EQ(sum,1.0);
}

TEST(practica_2,rango_intervalo_continuo){
    auto val = rand_min_max_continuo(0,1);
    EXPECT_TRUE((val >= 0) && (val <= 1));
}

TEST(practica_2,media_intervalo_continuo){
    ASSERT_NEAR(media_intervalo_continuo(0,1,_10M_),3.14,0.009);
}

TEST(practica_2,permutaciones){
    ASSERT_EQ(permutaciones(_10M_),13888);
}