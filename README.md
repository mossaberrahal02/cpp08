# cpp08
Time complexity:
    Time complexity is a way to describe how the running time of an algorithm increases as the size of the input increases.
    expressed using Big O notation (like O(n), O(n²), O(log n), etc.). It describes the upper bound of an algorithm's running time, how fast it grows in the worst-case scenario, relative to the input size.
    Step 1: Identify the input size:
        Let’s call it n. This could be the number of elements in an array, the number of nodes in a graph, etc.
    Step 2: Count the operations
        Look for loops, recursive calls, or repeated operations. You count how many times they run in terms of n.
        
        Example: Constant Time (O(1))
        ```
        def get_first_element(arr):
            return arr[0]
        ```
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
        Example: Cubic Time (O(n³))
        ```
        def print_all_triplets(arr):
            for i in range(len(arr)):
                for j in range(len(arr)):
                    for k in range(len(arr)):
                        print(arr[i], arr[j], arr[k])
        ```


        ## Example: Logarithmic Example
            ```i = 1
            while i < n:
                print(i)
                i *= 2```
        Here, the value of i doubles with each iteration, starting from 1. So instead of increasing by a constant amount (like adding 1), the value of i grows exponentially.

        How many times will the loop run? The value of i doubles each time, so we are essentially looking for how many times you can double 1 before reaching n. This is logarithmic growth.
        Initial Value of i: Starts at 1
        Each Iteration: The value of i is multiplied by 2 (i.e., i becomes 2, 4, 8, 16, etc.)
        Stopping Condition: The loop continues until i reaches or exceeds n
        After 1 iteration, i = 2.
        After 2 iterations, i = 4.
        After 3 iterations, i = 8, and so on.

        We need to figure out the value of k such that 2^k is greater than or equal to n. So, we set up the inequality:

        2^k ≥ n

        Taking the logarithm base 2 of both sides:

        k ≥ log⁡2(n)

        So, after n iterations, i will be approximately log₂(n). This is why we say the number of iterations grows logarithmically with n.


        Example exponential time complexity:
        ```def recursive_example(n):
            if n <= 0:
                return
            print(n)
            recursive_example(n - 1)
            recursive_example(n - 1)```

        The function calls itself twice for each value of n, creating a binary tree of recursive calls. The height of the tree is n, and at each level, the number of calls doubles.

        You can see that for each level of recursion, the number of calls doubles. 
        
        This results in O(2^n) time complexity.

        Example : Linear Recursive call
        ```
        def divide_and_conquer(n):
            if n <= 1:
                return
            divide_and_conquer(n // 2)
            divide_and_conquer(n // 2)
        Here, at each level, nn is halved. This is a classic divide and conquer approach.

        The number of recursive calls grows exponentially (similar to the 2n2n case from earlier), but at each level, the problem size is halved.
        
        In this case, the time complexity is logarithmic in nature but with additional work at each level, making it O(nlog⁡n)O(nlogn) for many divide-and-conquer algorithms (e.g., mergesort, quicksort).

        Time Complexity: O(nlog⁡n)
        ```
        
        Example: Factorial Time Complexity

        the number of operations grows extremely fast as nn increases
        n!=n×(n−1)×(n−2)×⋯×1

        The Traveling Salesman Problem (TSP)
        Permutations (Generating all permutations of a set)

        Time Complexity: O(n!)
        Factorial time complexity is extremely inefficient because as nn increases, the number of operations grows incredibly fast.



Standard Template Library (STL)

STL in C++ is a powerful collection of template classes and functions that provide generic data structures and algorithms.

containers, iterators, algorithms, and function objects.

I. Containers

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
