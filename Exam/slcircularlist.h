#ifndef SLCIRCULARLIST_H
#define SLCIRCULARLIST_H

#include <iterator>

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
class SLCircularList
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
            first->next = newNode;
            last = newNode;
            last->next = newNode;
        }

        auto prevFirst = first;
        first = newNode;
        last->next = nullptr;
        first->next = prevFirst;
    }

private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
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
