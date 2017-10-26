//
// Created by zotho on 26.10.17.
//

#ifndef LAB05_ALGORYTHM_H
#define LAB05_ALGORYTHM_H

#include <cstddef>

namespace alg {
/*
    template<class T_Arr, class T_Value>
    struct get {
        T_Value operator()(const T_Arr Arr) const {
            return Arr;
        };
    };

    template<class T_Value>
    struct less {
        bool operator()(const T_Value lhs, const T_Value rhs) const {
            return lhs < rhs;
        };
    };
*/
    template<class T_Arr, class T_Get/* = get<T_Arr, T_Value>*/,
            class T_Compare/* = less<T_Value> */>
    void quicksort(T_Arr *Arr, size_t left, size_t right, T_Compare comparator, T_Get getter);

    template<class T_Arr>
    void swap(T_Arr *Arr, size_t left, size_t right);

}
#endif //LAB05_ALGORYTHM_H