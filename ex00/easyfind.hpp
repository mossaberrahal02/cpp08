#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
int eazyfind(T & container, int toFind)
{
    T::iterator it = container.begin();
    for (it = container.begin(); it != container.end(); it++)
    {
        return (it.find())
    }
    return 0;
}
#endif
