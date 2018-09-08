#include <gtest/gtest.h>
#include <math/racional.hpp>

Racional a(2,3), b(4,7);

TEST(Racional,crear){
    ASSERT_EQ(a.den(),3);
    ASSERT_EQ(a.num(),2);
}