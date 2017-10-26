//
// Created by zotho on 23.10.17.
//
#ifndef LAB05_MAP_H
#define LAB05_MAP_H

template <class T>
struct less{
    bool operator()(const T lhs, const T rhs) const
    {
        return lhs < rhs;
    };
};

template<class T1, class T2>
struct pair {
    T1 Key;
    T2 Value;
};

template<class T_Arr, class T_Value>
struct get {
    T_Value operator()(const T_Arr Arr) const {
        return Arr.Key;
    };
};

template <class T_Key, class T, class T_Compare = less<T_Key>, class T_Get = get<pair<T_Key, T>, T_Key> >
class Map {
public:
    Map();
    Map(const Map& other);
    Map(const pair<T_Key, T> *other, size_t size);
    ~Map();
    Map<T_Key, T, T_Compare, T_Get> operator + (const Map<T_Key, T, T_Compare, T_Get> &other) const;
    Map<T_Key, T, T_Compare, T_Get> operator + (const pair<T_Key, T> &other) const;
   // Map& operator*(const Map& other);
   // Map& operator-(const Map& other);
    Map& operator=(const Map& other);
    void show(std::ostream &os = std::cout);
    ssize_t find(T_Key key, size_t left = 0, size_t right = 0); //-1 = not find
    void sort();
private:
    pair<T_Key, T>* array;
    size_t size;
    size_t capacity;
    T_Compare comparator;
    T_Get getter;

    void resize(size_t new_size);
    void expand();
    void copy(const Map &other, size_t start = 0);
};

#endif //LAB05_MAP_He
