#include "slcircularlist.h"

template<typename ValueType>
SLLIterator<ValueType>::SLLIterator(Node<ValueType> *p) :
    p(p)
{

}

template<typename ValueType>
SLLIterator<ValueType>::SLLIterator(const SLLIterator& it) :
    p(it.p)
{

}

template<typename ValueType>
bool SLLIterator<ValueType>::operator!=(SLLIterator const& other) const
{
    return p != other.p;
}

template<typename ValueType>
bool SLLIterator<ValueType>::operator==(SLLIterator const& other) const
{
    return p == other.p;
}

template<typename ValueType>
typename SLLIterator<ValueType>::reference SLLIterator<ValueType>::operator*() const
{
    return p->Data;
}

template<typename ValueType>
SLLIterator<ValueType> &SLLIterator<ValueType>::operator++()
{
    p = p->next;
    return *this;
}
