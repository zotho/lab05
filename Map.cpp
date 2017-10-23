//
// Created by zotho on 23.10.17.
//
#include <iostream>
#include "Map.h"

Map::Map() :    array(NULL),
                size(0),
                capacity(0){
}

Map::Map(const Map &other) {
    operator=(other);
}

Map::~Map() {

}

Map &Map::operator+(const Map &other) {
    return <#initializer#>;
}

Map &Map::operator*(const Map &other) {
    return <#initializer#>;
}

Map &Map::operator-(const Map &other) {
    return <#initializer#>;
}

Map &Map::operator=(const Map &other) {
    if(this != &other) {
        size = other.size;
        expand();
        copy(other);
    }
    return *this;
}

void Map::show(std::ostream &os) {

}

template <class T_Key, class T>
void Map<T_Key, T>::resize(size_t new_size) {
    if(size == new_size) return;
    if(capacity != 0){          //RESIZE ARRAY
        capacity = new_size + 10;
        pair<const T_Key, T>* tmp_array = new pair<T_Key, T> [capacity];
        size_t copy_size = size < new_size ? size : new_size;
        for(size_t i = 0; i < copy_size; ++i) {
            tmp_array->Key = array->Key;
            tmp_array->Value = array->Value;
        }
        size = copy_size;
        delete[] array;
        array = tmp_array;
        return;
    } else {                    //EMPTY ARRAY
        capacity = new_size + 10;
        array = new pair<T_Key, T> [capacity];
        size = new_size;
        return;
    }
}

template <class T_Key, class T>
void Map<T_Key, T>::expand() {
    if(size == capacity) return;
    if(capacity != 0){          //EXPAND ARRAY
        capacity = size;
        pair<const T_Key, T>* tmp_array = new pair<T_Key, T> [size];
        delete[] array;
        array = tmp_array;
        return;
    } else {                    //EMPTY ARRAY
        capacity = size;
        array = new pair<T_Key, T> [capacity];
        return;
    }
}

void Map::copy(const Map &other) {

}
