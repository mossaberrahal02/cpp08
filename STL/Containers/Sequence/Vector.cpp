/**
* A dynamic array. It provides fast random access and allows dynamic resizing.
* Insertion/deletion at the end is O(1), but
* inserting/deleting in the middle is O(n).
*/

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector
{
    private:
        T* data;//pointer to the array
        size_t capacity;//the allocated size of the array
        size_t size;//the current number of the items in the vector
        void resize(size_t new_capacity)
        {
            T* new_data = new T[new_capacity];//allocate new memory
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    public:
        MyVector():data(NULL), size(0), capacity(0)
        {

        }
        ~MyVector()
        {
            delete [] data;
        }
        void push_back(const T & value)
        {
            if(size == capacity)
                resize(capacity == 0 ? 1 : capacity * 2);
            data[size++] = value;
        }
        void pop_back()
        {
            if(size > 0)
                --size;
        }
        T & at(size_t index)
        {
            if(index >= size)
                throw std::out_of_range("index out of range");
            return data[index];
        }
        T & operator[](size_t index)
        {
            return(at(index));
        }
        //...
};

int main()
{
    MyVector<int> myvector;
    myvector.push_back(1337);
    myvector.push_back(1337);
    myvector.push_back(1337);
    myvector.push_back(1337);
    for (int i = 0; i < 4 ; i++)
    {
        std::cout << myvector.at(i) << std::endl;
    }
    myvector.pop_back();
    for (int i = 0; i < 3 ; i++)
    {
        std::cout << myvector.at(i) << std::endl;
    }
    // std::cout << myvector[0] << std::endl;
    return 0;
}