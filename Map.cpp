//
// Created by zotho on 23.10.17.
//
#include <iostream>
#include "Map.h"
#include "Algorythm.h"
#include "Algorythm.cpp"

template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get>::Map() :   array(NULL),
                                    size(0),
                                    capacity(0){
    //std::cout << "Map()" << std::endl;
}

template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get>::Map(const Map &other) {
    std::cout << "Map(map)" << std::endl;
    operator=(other);
}

template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get>::Map(const pair <T_Key, T> *other, size_t size) :      array(NULL),
                                                                                size(size),
                                                                                capacity(0){
    //std::cout << "Map(pair)" << std::endl;
    expand();
    for(size_t i = 0; i < size; i++) {
        array[i].Key = other[i].Key;
        array[i].Value = other[i].Value;
    }
}

template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get>::~Map() {
    //std::cout << "~Map" << std::endl;
    if(array != NULL) {
        delete[] array;
    }
}

template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get> Map<T_Key, T, T_Compare, T_Get>::operator + (Map<T_Key, T, T_Compare, T_Get> const &other) const{
    std::cout << "Map + " << std::endl;
    Map<T_Key, T, T_Compare, T_Get> out;
    out.resize(size + other.size);
    out.copy(*this);
    out.copy(other, size);
    return out;
}

template<class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get> Map<T_Key, T, T_Compare, T_Get>::operator + (const pair<T_Key, T> &other) const{
    //std::cout << "Map + pair" << std::endl;
    Map<T_Key, T, T_Compare, T_Get> out;
    out.resize(size + 1);
    out.array[out.size - 1].Key = other.Key;
    out.array[out.size - 1].Value = other.Value;
    return out;
}
/*
Map &Map::operator*(const Map &other) {
    return <#initializer#>;
}

Map &Map::operator-(const Map &other) {
    return <#initializer#>;
}
*/
template <class T_Key, class T, class T_Compare, class T_Get>
Map<T_Key, T, T_Compare, T_Get> &Map<T_Key, T, T_Compare, T_Get>::operator=(const Map<T_Key, T, T_Compare, T_Get> &other) {
    //std::cout << "Map = " << std::endl;
    if(this != &other) {
        size = other.size;
        expand();
        copy(other);
    }
    return *this;
}

template <class T_Key, class T, class T_Compare, class T_Get>
void Map<T_Key, T, T_Compare, T_Get>::show(std::ostream &os) {
    for(size_t i = 0; i < size; ++i) {
        os << "\"" << array[i].Key << "\"\t\"" << array[i].Value << "\"" << std::endl;
    }
}

template <class T_Key, class T, class T_Compare, class T_Get>
ssize_t Map<T_Key, T, T_Compare, T_Get>::find(T_Key key, size_t left, size_t right) {
    ssize_t out = -1;
    if(left == 0 && right == 0) {
        left = 0;
        right = size - 1;
    }
    if((right - left ) == 1 || (right - left) == 0) {
        if(array[right].Key == key) {
            out = right;
        }
        if(array[left].Key == key) {
            out = left;
        }
    } else if((right - left) >= 2) {
        size_t middle = right - (right - left)/2;
        if(comparator(key,array[middle].Key)) {       //???
            out = find(key, left, middle);
        } else {
            out = find(key, middle, right);
        }
    }
    return out;
}

template <class T_Key, class T, class T_Compare, class T_Get>
void Map<T_Key, T, T_Compare, T_Get>::resize(const size_t new_size) {
    if(size == new_size)
        return;
    if(capacity != 0){          //RESIZE ARRAY
        capacity = new_size + 10;
        pair<T_Key, T>* tmp_array = new pair<T_Key, T> [capacity];
        size_t copy_size = size < new_size ? size : new_size;
        for(size_t i = 0; i < copy_size; ++i) {
            tmp_array[i].Key = array[i].Key;
            tmp_array[i].Value = array[i].Value;
            //std::cout << i << "-->Copied Key: " << array[i].Key << "\tCopied Value: " << array[i].Value << std::endl;
        }
        delete[] array;
        array = tmp_array;
    } else {                    //EMPTY ARRAY
        capacity = new_size + 10;
        array = new pair<T_Key, T> [capacity];
    }
    size = new_size;
}

template <class T_Key, class T, class T_Compare, class T_Get>
void Map<T_Key, T, T_Compare, T_Get>::expand() {
    if(size == capacity) return;
    if(capacity != 0){          //EXPAND ARRAY
        capacity = size + 10;
        pair<T_Key, T>* tmp_array = new pair<T_Key, T> [size];//ERROR
        delete[] array;
        array = tmp_array;
    } else {                    //EMPTY ARRAY
        capacity = size + 10;
        array = new pair<T_Key, T> [capacity];
    }
}

template <class T_Key, class T, class T_Compare, class T_Get>
void Map<T_Key, T, T_Compare, T_Get>::copy(const Map<T_Key, T, T_Compare, T_Get> &other, size_t start) {
    size_t copy_size = ((size - start) < other.size) ? (size - start) : other.size;
    for(size_t i = 0; i < copy_size; ++i) {
        array[i + start].Key = other.array[i].Key;
        array[i + start].Value = other.array[i].Value;
        //std::cout << i + start << "-->Copied Key: " << array[i].Key << "\tCopied Value: " << array[i].Value << std::endl;
    }
}

template <class T_Key, class T, class T_Compare, class T_Get>
void Map<T_Key, T, T_Compare, T_Get>::sort() {
    alg::quicksort(array, (size_t)0, size - 1, comparator, getter);
}

