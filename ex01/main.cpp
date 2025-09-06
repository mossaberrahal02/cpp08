#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(50);
        sp.displayContainer();
        sp.addNumber(0);
        sp.addNumber(1);
        sp.addNumber(100);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.displayContainer();
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Expected: 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // Expected: 14

        std::vector<int> moreNumbers;
        moreNumbers.push_back(43);
        moreNumbers.push_back(7);
        moreNumbers.push_back(1);
        moreNumbers.push_back(0);
        moreNumbers.push_back(100);
        sp.addNumbersRange(moreNumbers.begin(), moreNumbers.end());
        sp.displayContainer();
        std::cout << "Shortest Span after adding more numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span after adding more numbers: " << sp.longestSpan() << std::endl;
        Span sp2(1);
        sp2.displayContainer();
        sp2.addNumber(10);
        sp2.displayContainer();
        std::cout << "Shortest Span with 1 element: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span with 1 element: " << sp2.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
