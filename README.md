# cpp08
Time complexity:
    Time complexity is a way to describe how the running time of an algorithm increases as the size of the input increases.
    expressed using Big O notation (like O(n), O(n²), O(log n), etc.). It describes the upper bound of an algorithm's running time, how fast it grows in the worst-case scenario, relative to the input size.
    Step 1: Identify the input size:
        Let’s call it n. This could be the number of elements in an array, the number of nodes in a graph, etc.
    Step 2: Count the operations
        Look for loops, recursive calls, or repeated operations. You count how many times they run in terms of n.
        
        Example: A simple loop
        ```for i in range(n):
            print(i)```
        This loop runs n times.
        Time complexity: O(n)

        Example: Nested loop
        ```
            for i in range(n):
                for j in range(n):
                    print(i, j)```
        Outer loop runs n times.
        Inner loop runs n times for each iteration of the outer loop.
        Total operations: n * n = n²
        Time complexity: O(n²)

        Example: Logarithmic Example
            ```i = 1
            while i < n:
                print(i)
                i *= 2```
        


Standard Template Library (STL)

1. Sequence Containers
2. Associative Containers
3. Unordered Containers
4. Container Adapters
5. Other Useful Components


1. Sequence Containers:

vector<T>:
    A dynamic array that can grow and shrink in size.
    Good for scenarios where you add/remove elements from the end (push_back, pop_back).
    Example: std::vector<int> v = {1, 2, 3};
