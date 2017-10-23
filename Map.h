//
// Created by zotho on 23.10.17.
//
#ifndef LAB05_MAP_H
#define LAB05_MAP_H


template <class T>
struct less {
    bool operator()(const T &lhs, const T &rhs) const
    {
        return lhs < rhs;
    };
} less;

template<class T1, class T2>
struct pair {
    T1 Key;
    T2 Value;
} pair;

template <class T_Key, class T, class T_Compare = less<T_Key> >
class Map {
public:
    Map();
    Map(const Map& other);
    ~Map();
    Map& operator+(const Map& other);
    Map& operator*(const Map& other);
    Map& operator-(const Map& other);
    Map& operator=(const Map& other);
    void show(std::ostream &os = std::cout);
private:
    pair<const T_Key, T_Compare>* array;
    size_t size;
    size_t capacity;

    void resize(size_t new_size = size);
    void expand();
    void copy(const Map &other);
};

#endif //LAB05_MAP_He
