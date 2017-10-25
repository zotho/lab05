//
// Created by zotho on 23.10.17.
//
#include <iostream>
#include <functional>
#include "Map.h"
#include "Map.cpp"

int main(){
    const struct pair <int, char*>a[3] = {{5, "A"}, {4, "B"}, {3, "C"}};
    Map <int, char*, std::less<int> > m(a, 3);

    m.show();

    std::cout << std::endl;

    const struct pair <int, char*>b[2] = {{2, "D"}, {1, "E"}};
    Map <int, char*, std::less<int> > m1(b, 2);
    //m1 = m;
    m1.show();
    std::cout << std::endl;
    m1 + m;
    m1.show();

    return 0;
}