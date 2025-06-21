#include <iostream>
#include <stdexcept>
#include <iterator>

template <typename T, std::size_t N>
class array {
public:
    T data[N];
    array(){}

    // Constructor that allows initializing the array with a list of values
    array(std::initializer_list<T> init) {
        if (init.size() > N) {
            throw std::out_of_range("Initializer list too large for array");
        }
        std::copy(init.begin(), init.end(), data);
    }
    array(const T* init, std::size_t size) {
        std::cout << "from the constructor that uses the array for initialisation"<<std::endl;
        if (size > N) {
            throw std::out_of_range("Initializer array too large for array");
        }
        std::copy(init, init + size, data);
    }

    // Accessor methods

    // Access element with bounds checking
    T& at(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Non-checked access (like C-style array indexing)
    T& operator[](std::size_t index) {
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    // Size of the array (fixed at compile-time)
    constexpr std::size_t size() const noexcept {
        return N;
    }

    // Front and back element access
    T& front() { return data[0]; }
    const T& front() const { return data[0]; }
    T& back() { return data[N - 1]; }
    const T& back() const { return data[N - 1]; }

    // Begin and end iterators
    T* begin() noexcept { return &data[0]; }
    const T* begin() const noexcept { return &data[0]; }
    T* end() noexcept { return &data[0] + N; }
    const T* end() const noexcept { return &data[0] + N; }

    // Fill the entire array with a specific value
    void fill(const T& value) {
        std::fill(begin(), end(), value);
    }
};

int main() {
    // Creating an array of integers with a size of 5
    array<int, 5> arr = {1, 2, 3, 4, 5};
    int values[] = {1, 2, 3};
    array<int, 5> arr_(values, 3);
    // Accessing elements
    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    // Access using at() with bounds checking
    try {
        std::cout << "Element at index 3: " << arr.at(3) << std::endl;
        std::cout << "Element at index 10: " << arr.at(10) << std::endl;  // Throws exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Accessing elements using operator[]
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    // Iterating over the array
    std::cout << "Array elements: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;


    std::cout << "First element: " << arr_.front() << std::endl;
    std::cout << "Last element: " << arr_.back() << std::endl;

    // Access using at() with bounds checking
    try {
        std::cout << "Element at index 3: " << arr_.at(3) << std::endl;
        std::cout << "Element at index 10: " << arr_.at(10) << std::endl;  // Throws exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Accessing elements using operator[]
    std::cout << "Element at index 2: " << arr_[2] << std::endl;

    // Iterating over the array
    std::cout << "Array elements: ";
    for (const auto& elem : arr_) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
