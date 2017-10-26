//
// Created by zotho on 23.10.17.
//
#include <iostream>
//#include <functional>
#include "Map.h"
#include "Map.cpp"

int main(){
    const struct pair <int, int>a[3] = {{5, 1}, {4, 2}, {3, 3}};
    const struct pair <int, int>b[2] = {{2, 4}, {1, 5}};

    Map <int, int> m(a, 3);
    Map <int, int> m1(b, 2);
    Map <int, int> m2, m3;

    m.show();
    std::cout << std::endl;
    m1.show();
    std::cout << std::endl;
    m2 = m + m1;
    m3 = m1 + m;
    m.show();
    std::cout << std::endl;
    m1.show();
    std::cout << std::endl;
    m2.show();
    std::cout << std::endl;
    m3.show();
    std::cout << std::endl;
    std::cout << m2.find(1) << std::endl;
    std::cout << m2.find(2) << std::endl;
    std::cout << m2.find(3) << std::endl;
    std::cout << m2.find(4) << std::endl;
    std::cout << m2.find(5) << std::endl;

    m3.sort();

    return 0;
}
