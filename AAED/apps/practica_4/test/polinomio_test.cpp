#include <gtest/gtest.h>
#include <math/polinomio.hpp>

Polinomio a("2x^5+3x^1+1",5);
Polinomio b("4x^4+4x^1+2",4);

TEST(PolinomioTest,Creacion){
    EXPECT_EQ((int)a.grado(),5);
    EXPECT_EQ((int)b.grado(),4);
}

TEST(PolinomioTest,Suma){
    Polinomio c = (a + b);
    EXPECT_STREQ(c.to_string().c_str(),"2x^5 + 4x^4 + 7x + 3");
}

TEST(PolinomioTest,Resta){
     Polinomio c = (a - b);
    EXPECT_STREQ(c.to_string().c_str(),"2x^5 + -4x^4 + -1x + -1");
}

TEST(PolinomioTest,Producto){
    Polinomio c = (a * b);

    EXPECT_STREQ(c.to_string().c_str(),"8x^9 + 8x^6 + 16x^5 + 4x^4 + 12x^2 + 10x + 2");
}

TEST(PolinomioTest,Derivada){
    EXPECT_STREQ(derivada(a).to_string().c_str(),"10x^4 +  + 3");
    EXPECT_STREQ(derivada(b).to_string().c_str(),"16x^3 +  + 4");
}