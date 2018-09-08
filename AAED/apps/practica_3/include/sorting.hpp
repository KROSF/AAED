#ifndef SORTING_HPP
#define SORTING_HPP

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

template <typename T>
void bubble_sort(vector<T>& v){
    unsigned int size = v.size();
    for( unsigned int i = 1 ; i < size ; ++i )
        for( unsigned int j = 0; j < size - i ; ++j )
            if(v[j] > v [j+1] )
                swap(v[j],v[j+1]);
}


template <typename T>
void insertion_sort(vector<T>& v){
    unsigned int j, size = v.size();
    for( unsigned int i = 0 ; i < size ; ++i ){
        j = i;
        while( j > 0 && v[j-1] > v[j] ){
            swap(v[j],v[j-1]);
            --j;
        }
    }
}

template <typename T>
void selection_sort(vector<T>& v){
    unsigned int min_index, j, size = v.size();

    for( unsigned int i = 0 ; i < size - 1 ; ++i ){
        min_index = i;
        for(j = i+1 ; j < size ; ++j )
            if(v[j] < v[min_index])
                min_index = j;

        swap(v[min_index],v[i]);
    }
}

template <typename T>
void generate_vector(vector<T>& v,int i){
    int j , k = v.size();
    for( j = 0 ; j < i ; ++j )
        v.push_back( k + j );
}

#endif
