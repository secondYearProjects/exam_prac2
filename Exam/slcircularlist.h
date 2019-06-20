#ifndef SLCIRCULARLIST_H
#define SLCIRCULARLIST_H

#include <iterator>
#include <algorithm>
#include "tovector.h"

template<typename ValueType>
class SLLIterator;

template <typename T>
struct Node
{
    Node(T &val){
        Data = val;
        next = nullptr;
    }
    T Data;
    Node *next;
};

template <typename T>
    class SLCircularList: public ToVector<T>
{
public:
    SLCircularList() {}

    typedef SLLIterator<Node<T>> iterator;
    typedef SLLIterator<const Node<T>> const_iterator;

    iterator begin(){
        return iterator(first);
    }

    iterator end(){
        return iterator(nullptr);
    }

    void add(T val){
        auto newNode = new Node<T>(val);
        if (first == nullptr) {
            first = newNode;
            first->next = nullptr;
            return;
        }

        auto prevFirst = first;
        first = newNode;
        first->next = prevFirst;
    }

    void del(T val){
        auto v = toVector();
        std::reverse(v.begin(),v.end());
        clear();
        bool found = false;
        for (auto el:v){
            if (val != el || found){
                add(el);
            }
            else
                found = true;
        }
    }

    void clear() {
        auto curr = first;
        first = nullptr;
        while(curr){
            auto toDel = curr;
            curr= curr->next;
            delete toDel;
        }
    }

    std::vector<T> toVector() const{
        std::vector<T> res;
        auto curr = first;
        if (curr == nullptr)
            return res;
        while(curr != nullptr){
            res.push_back(curr->Data);
            curr = curr->next;
        }
        return res;
    }

private:
    Node<T> *first = nullptr;
};


template<typename ValueType>
class SLLIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
    template <typename T>
    friend class SLCircularList;
private:
    SLLIterator(Node<ValueType>* p);
public:
    SLLIterator(const SLLIterator &it);

    bool operator!=(SLLIterator const& other) const;
    bool operator==(SLLIterator const& other) const;
    typename SLLIterator::reference operator*() const;
    SLLIterator& operator++();
private:
    Node<ValueType>* p;
};

#endif // SLCIRCULARLIST_H
