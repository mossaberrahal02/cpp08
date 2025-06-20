/**
*A dynamic array. It provides fast random access and allows dynamic resizing.
* Insertion/deletion at the end is O(1), but inserting/deleting in the middle is O(n).
*/

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;//template class
    v.push_back(1);
    std::cout << v[0] << std::endl;//or v.at(0)

    return 0;
}