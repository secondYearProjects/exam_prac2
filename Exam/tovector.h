#ifndef TOVECTOR_H
#define TOVECTOR_H

#include <vector>

template <typename T>
class ToVector{
public:
    virtual std::vector<T> toVector() const = 0;
private:
};

#endif // TOVECTOR_H
