//
// Created by zotho on 26.10.17.
//
#include "Algorythm.h"

using namespace alg;

template<class T_Value, class T_Arr, class T_Get/* = get<T_Arr, T_Value>*/,
        class T_Compare/* = less<T_Get> */>
void quicksort(T_Arr *Arr, size_t left, size_t right, T_Compare comparator, T_Get getter) {
    size_t i = left, j = right;
    //int tmp;
    size_t pivot = getter(Arr[(left + right) / 2]);

    /* partition */
    while (i <= j) {
        while (comparator(getter(Arr[i]), getter(pivot)))
            ++i;
        while (comparator(getter(pivot), getter(Arr[j])))
            --j;
        if (i <= j) {
            /*tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;*/
            swap(Arr, i, j);
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quicksort(Arr, left, j, comparator, getter);
    if (i < right)
        quicksort(Arr, i, right, comparator, getter);
}

template<class T_Arr>
void swap(T_Arr *Arr, size_t left, size_t right) {
    T_Arr temp(Arr[left]);
    Arr[left] = Arr[right];
    Arr[right] = Arr[temp];

}