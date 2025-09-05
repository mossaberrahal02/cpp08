#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        // Test with Span(5)
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Expected: 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // Expected: 14

        // Test adding numbers from a range
        std::vector<int> moreNumbers = {1, 5, 12, 17, 25};
        sp.addNumbersRange(moreNumbers.begin(), moreNumbers.end());
        std::cout << "Shortest Span after adding more numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span after adding more numbers: " << sp.longestSpan() << std::endl;

        // Test edge case with only 1 element
        Span sp2(1);
        sp2.addNumber(10);
        std::cout << "Shortest Span with 1 element: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span with 1 element: " << sp2.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
