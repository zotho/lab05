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
};

template<class T1, class T2>
struct pair {
    T1 Key;
    T2 Value;
};

template <class T_Key, class T, class T_Compare = less<T_Key> >
class Map {
public:
    Map();
    Map(const Map& other);
    Map(const pair<T_Key, T> *other, size_t size);
    ~Map();
    Map& operator+(const Map& other);
    Map& operator*(const Map& other);
    Map& operator-(const Map& other);
    Map& operator=(const Map& other);
    void show(std::ostream &os = std::cout);
private:
    pair<T_Key, T>* array;
    size_t size;
    size_t capacity;

    void resize(size_t new_size);
    void expand();
    void copy(const Map &other, size_t start = 0);
};

#endif //LAB05_MAP_He
