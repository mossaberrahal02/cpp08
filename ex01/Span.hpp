#pragma once

#include <vector>
#include <iostream>
#include <algorithm> 
#include <stdexcept>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;
public:
    Span(unsigned int n);

    void addNumber(int num);
    template <typename T>
    void addNumbersRange(T first, T last);
    int shortestSpan();
    int longestSpan();
};