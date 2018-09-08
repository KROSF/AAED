#include <gtest/gtest.h>
#include <sort/sorting.hpp>

TEST(practica_3,bubble_sort){
    std::vector<int> v ={0,9,8,7,6,5,4,3,2,1};
    std::random_shuffle(v.begin(),v.end());
    bubble_sort(v);
    for (int i = 0; i < 10; ++i)
        ASSERT_EQ(v[0],0);
}

TEST(practica_3,insertion_sort){
    std::vector<int> v ={0,9,8,7,6,5,4,3,2,1};
    std::random_shuffle(v.begin(),v.end());
    insertion_sort(v);
    for (int i = 0; i < 10; ++i)
        ASSERT_EQ(v[0],0);
}

TEST(practica_3,selection_sort){
    std::vector<int> v ={0,9,8,7,6,5,4,3,2,1};
    std::random_shuffle(v.begin(),v.end());
    selection_sort(v);
    for (int i = 0; i < 10; ++i)
        ASSERT_EQ(v[0],0);
}