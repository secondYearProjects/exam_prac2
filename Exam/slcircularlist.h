#ifndef SLCIRCULARLIST_H
#define SLCIRCULARLIST_H

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
        last->next = first;
        first->next = prevFirst;
    }

private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
};

#endif // SLCIRCULARLIST_H
