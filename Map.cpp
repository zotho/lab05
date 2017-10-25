//
// Created by zotho on 23.10.17.
//
#include <iostream>
#include "Map.h"

template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare>::Map() :   array(NULL),
                                    size(0),
                                    capacity(0){
    std::cout << "Map" << std::endl;
}

template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare>::Map(const Map &other) {
    operator=(other);
}

template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare>::Map(const pair <T_Key, T> *other, size_t size) :      array(NULL),
                                                                                size(size),
                                                                                capacity(0){
    expand();
    for(size_t i = 0; i < size; i++) {
        array[i].Key = other[i].Key;
        array[i].Value = other[i].Value;
    }
}

template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare>::~Map() {
    if(array != NULL) {
        delete[] array;
    }
    std::cout << "~Map" << std::endl;
}

template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare> &Map<T_Key, T, T_Compare>::operator+(const Map<T_Key, T, T_Compare> &other) {

    resize(size + other.size);
    std::cout << "check0" << std::endl;
    show();
    std::cout << "check1" << std::endl;
    copy(other, size - other.size);
    return *this;
}
/*
Map &Map::operator*(const Map &other) {
    return <#initializer#>;
}

Map &Map::operator-(const Map &other) {
    return <#initializer#>;
}
*/
template <class T_Key, class T, class T_Compare>
Map<T_Key, T, T_Compare> &Map<T_Key, T, T_Compare>::operator=(const Map<T_Key, T, T_Compare> &other) {
    if(this != &other) {
        size = other.size;
        expand();
        copy(other);
    }
    std::cout << "Map=" << std::endl;
    return *this;
}

template <class T_Key, class T, class T_Compare>
void Map<T_Key, T, T_Compare>::show(std::ostream &os) {
    for(size_t i = 0; i < size; ++i) {
        os << "\"" << array[i].Key << "\"\t\"" << array[i].Value << "\"" << std::endl;
    }
}

template <class T_Key, class T, class T_Compare>
void Map<T_Key, T, T_Compare>::resize(const size_t new_size) {
    if(size == new_size)
        return;
    if(capacity != 0){          //RESIZE ARRAY
        capacity = new_size + 10;
        pair<T_Key, T>* tmp_array = new pair<T_Key, T> [capacity];
        size_t copy_size = size < new_size ? size : new_size;
        for(size_t i = 0; i < copy_size; ++i) {
            tmp_array[i].Key = array[i].Key;
            tmp_array[i].Value = array[i].Value;
        }
        delete[] array;
        array = tmp_array;
    } else {                    //EMPTY ARRAY
        capacity = new_size + 10;
        array = new pair<T_Key, T> [capacity];
    }
    size = new_size;
}

template <class T_Key, class T, class T_Compare>
void Map<T_Key, T, T_Compare>::expand() {
    if(size == capacity) return;
    if(capacity != 0){          //EXPAND ARRAY
        capacity = size + 10;
        pair<T_Key, T>* tmp_array = new pair<T_Key, T> [size];
        delete[] array;
        array = tmp_array;
    } else {                    //EMPTY ARRAY
        capacity = size + 10;
        array = new pair<T_Key, T> [capacity];
    }
}

template <class T_Key, class T, class T_Compare>
void Map<T_Key, T, T_Compare>::copy(const Map<T_Key, T, T_Compare> &other, size_t start) {
    size_t copy_size = ((size - start) < other.size) ? (size - start) : other.size;
    for(size_t i = start; i < (copy_size + start); ++i) {
        array[i].Key = other.array[i].Key;
        array[i].Value = other.array[i].Value;
    }
}

