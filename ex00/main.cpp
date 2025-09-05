#include "easyfind.hpp"
#include <vector>
#include <exception>

int main()
{
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        try {
            std::vector<int>::const_iterator it = eazyFind(vec, 3);
            std::cout << "Found element: " << *it << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "---------------------"<< std::endl;
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        try {
            std::vector<int>::const_iterator it = eazyFind(vec, 6);
            std::cout << "Found element: " << *it << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "---------------------"<< std::endl;
    {
        std::vector<int> vec;
        
        try {
            std::vector<int>::const_iterator it = eazyFind(vec, 1);
            std::cout << "Found element: " << *it << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << "---------------------"<< std::endl;
    // {
    //     const std::vector<int> vec = {1, 2, 3, 4, 5};
        
    //     try {
    //         std::vector<int>::const_iterator it = eazyFind(vec, 4);
    //         std::cout << "Found element: " << *it << std::endl;
    //     }
    //     catch (const std::exception& e) {
    //         std::cout << "Error: " << e.what() << std::endl;
    //     }
    // }
    return 0;
}