#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}

void Span::addNumber(int num) {
    if (numbers.size() >= N) {
        throw std::overflow_error("Cannot add more numbers, Span is full.");
    }
    numbers.push_back(num);
}

// Template function to add a range of numbers (from iterators)
template <typename T>
void Span::addNumbersRange(T first, T last) {
    for (T it = first; it != last; ++it) {
        addNumber(*it);
    }
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Cannot find a span, not enough numbers.");
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Cannot find a span, not enough numbers.");
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return max - min;
}
