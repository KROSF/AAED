#include <gtest/gtest.h>
#include <math/racional.hpp>

Racional a(2,3), b(4,7);

TEST(Racional,crear){
    ASSERT_EQ(a.den(),3);
    ASSERT_EQ(a.num(),2);
}

TEST(Racional, operador_de_igualdad){
    ASSERT_TRUE( a == Racional(2,3));
    ASSERT_FALSE( a == Racional(3,2));
}

TEST(Racional, operador_de_desigualdad){
    ASSERT_TRUE( a != Racional(3,2));
    ASSERT_FALSE( a != Racional(2,3));
}

TEST(Racional, operador_menor){
    ASSERT_TRUE(Racional(11,35) < Racional(10,18));
    ASSERT_FALSE(Racional(22,22) < Racional(22,22));
    ASSERT_FALSE(Racional(23,2) < Racional(0,1));
}

TEST(Racional, operador_menor_igual){
    ASSERT_TRUE(Racional(11,35) <= Racional(10,18));
    ASSERT_TRUE(Racional(22,22) <= Racional(22,22));
    ASSERT_FALSE(Racional(23,2) <= Racional(0,1));
}

TEST(Racional, operador_mayor){
    ASSERT_TRUE(Racional(10,18) > Racional(11,35));
    ASSERT_FALSE(Racional(22,22) > Racional(22,22));
    ASSERT_FALSE(Racional(0,2) > Racional(23,1));
}

TEST(Racional, operador_mayor_igual){
    ASSERT_TRUE(Racional(10,18) >= Racional(11,35));
    ASSERT_TRUE(Racional(22,22) >= Racional(22,22));
    ASSERT_FALSE(Racional(0,2) >= Racional(23,1));
}

TEST(Racional, operador_suma){
    ASSERT_EQ(a+b,Racional(26,21));
    ASSERT_EQ(a+a,Racional(4,3));
}

TEST(Racional, operador_suma_asignacion){
    Racional t(2,3);
    t += 1;
    ASSERT_EQ(t,Racional(5,3));
}

TEST(Racional, operador_resta){
    ASSERT_EQ(a-b,Racional(2,21));
    ASSERT_EQ(a-a,Racional(0,3));
}

TEST(Racional, operador_resta_asignacion){
    Racional t(2,3);
    t -= 1;
    ASSERT_EQ(t,Racional(-1,3));
}

TEST(Racional, operador_producto){
    ASSERT_EQ(a*b,Racional(8,21));
    ASSERT_EQ(a*a,Racional(4,9));
}

TEST(Racional, operador_producto_asignacion){
    Racional t(2,3);
    t *= 1; 
    ASSERT_EQ(t,Racional(2,3));
    t *= 2;
    ASSERT_EQ(t,Racional(4,3));
}

TEST(Racional, operador_division){
    ASSERT_EQ(a/b,Racional(7,6));
    ASSERT_EQ(a/a,Racional(1,1));
    ASSERT_EQ(Racional(1,2)/Racional(23,2),Racional(1,23));
}

TEST(Racional, operador_division_asignacion){
    Racional t(2,3);
    t /= 1; 
    ASSERT_EQ(t,Racional(2,3));
    t /= 2;
    ASSERT_EQ(t,Racional(1,3));
}
