#pragma once
#include <iterator>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator eazyFind(const T &container, int i)
{
    typename T::const_iterator it = find(container.begin(), container.end(), i);
    if(it == container.end())
        throw std::runtime_error("no such element in the container with this value ");
    return it;
}