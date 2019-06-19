#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <functional>
#include <cstdlib>
#include <algorithm>

// 10.Insert, Quick, Heap, Count

template <typename T>
void insertSort(std::vector<T> &v, std::function<bool (T&,T&)> less){
    T temp;
    int item;
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
void insertSort(std::vector<T> &v){
    insertSort<T>(v,[](T&a,T&b){return a<b;});
}

template <typename T>
int partition (std::vector<T> &arr, int low, int high, std::function<bool (T&,T&)> less);

template <typename T>
void qs(std::vector<T> &arr, int low, int high, std::function<bool (T&,T&)> less)
{
    if (low < high)
    {
        int pi = partition(arr, low, high,less);

        qs(arr, low, pi - 1,less);
        qs(arr, pi + 1, high, less);
    }
}

template <typename T>
int partition (std::vector<T> &arr, int low, int high, std::function<bool (T&,T&)> less)
{
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (less(arr[j], pivot))
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(std::vector<T> &v, std::function<bool (T&,T&)> less){
    qs(v,0,v.size()-1,less);
}

template <typename T>
void quickSort(std::vector<T> &v) {
    quickSort<T>(v,[](T&a,T&b){return a<b;});
}



template <typename T>
void max_heapify(std::vector<T> &a, size_t size, size_t i, std::function<bool (T&,T&)> less) {
    size_t left =  (i + 1) * 2 - 1;
    size_t right = (i + 1) * 2;
    size_t largest = i;
    if (left < size && less(a[largest], a[left]))
        largest = left;
    if (right < size && less(a[largest],a[right]))
        largest = right;
    if (largest != i) {
        std::swap(a[i], a[largest]);
        max_heapify(a, size, largest, less);
    }
}

template <typename T>
void build_max_heap(std::vector<T> &a, size_t size, std::function<bool (T&,T&)> less) {
    for (int i = size / 2; i >= 0; i--) {
        max_heapify(a, size, i,less);
    }
}

template <typename T>
void heapSort(std::vector<T> &a, std::function<bool (T&,T&)> less) {
    build_max_heap(a, a.size(),less);
    size_t heap_size = a.size();
    for (int i = a.size()-1; i > 0; i--) {
        std::swap(a[0], a[i]);
        heap_size--;
        max_heapify(a, heap_size, 0, less);
    }
}

template <typename T>
void heapSort(std::vector<T> &a) {
    heapSort<T>(a,[](T&a,T&b){return a<b;});
}






#endif // SORTS_H
