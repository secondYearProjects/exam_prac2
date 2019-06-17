#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <functional>

// 10.Insert, Quick, Heap, Count


template <typename T>
void insertSort(std::vector<T> &v, std::function<bool (T&,T&)> less){
    T temp, item;
    for (int counter = 1; counter < v.size(); counter++)
    {
        temp = v[counter];
        item = counter-1;
        while(item >= 0 && less(temp, v[item]))
        {
            v[item + 1] = v[item];
            v[item] = temp;
            item--;
        }
    }
}

template <typename T>
bool standatdCMP(T& a, T& b) {
    return a<b;
}

template <typename T>
void insertSort(std::vector<T> &v){
    //std::function<bool (T&,T&)> less = standatdCMP;

    T temp, item;
    for (int counter = 1; counter < v.size(); counter++)
    {
        temp = v[counter];
        item = counter-1;
        while(item >= 0 && standatdCMP(temp, v[item]))
        {
            v[item + 1] = v[item];
            v[item] = temp;
            item--;
        }
    }
}

#endif // SORTS_H
