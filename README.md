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

containers, iterators, algorithms

#Three Pillars of STL

1) containers:
data structures that stores objects in memory

Category	    Examples	                                    When to Use

Sequence	    vector, list, deque, array, forward_list	    Store elements in a specific order, direct access by position
Associative	    set, multiset, map, multimap	                Store sorted elements, fast search (O(log n))
Unordered	    unordered_set, unordered_map, etc.	            Store unsorted elements, fastest average search (O(1))


1.1 Sequence Containers

*They store elements in the order you insert them and allow you to access elements based on position/index*

Container	    | Key Features	                                                                  | When to Use
vector	        | Dynamic array (fast random access, elements stored contiguously in memory)      | You know you’ll need fast index-based access and occasional resizing
list	        | Doubly linked list (fast insertion/removal anywhere, no random access)	      | Many insertions/removals in the middle
deque	        | Double-ended queue (fast insertion/removal at both ends, random access)         | Need to add/remove from front and back efficiently
array	        | Fixed-size array (compile-time size, contiguous memory)               	      |  Performance-critical, size known in advance
forward_list	| Singly linked list (saves memory, forward traversal only)	                      |  Lightweight list with only forward movement

time complexity
vector:                | Random access O(1), insert/remove at end O(1) amortized, insert/remove in middle O(n)
list / forward_list:   | No random access, insert/remove anywhere O(1) (with iterator)
deque:                 | Random access O(1), insert/remove at ends O(1)
array:                 | Random access O(1)


1.2 Associative Containers (key-value)

*They store elements in a sorted order (based on a comparison function, default is <) and allow*
*logarithmic search using balanced binary trees (usually Red-Black trees).*



(
Red-Black Tree?

    Balanced Structure: The self-balancing nature ensures that operations remain efficient even when the tree grows large.
    Guaranteed Performance: Even in the worst case, operations will always take logarithmic time.
    Versatile:  Red-Black Trees are commonly used in many real-world applications like:
                Associative containers in C++ STL (e.g., std::map, std::set).
                Used in databases and file systems where fast insertion and deletion are crucial.

Other Algorithms with Logarithmic Time Complexity ?

    O(log n) complexity

    Balanced binary search trees (like Red-Black Trees, AVL Trees, etc.): Search, insert, and delete operations can be done in O(log n) time.
    Heaps: Operations like insertion and deletion in a heap can also be done in logarithmic time.
    Exponentiation by squaring: Efficient algorithms for raising a number to a power, such as exponentiation by squaring, can be done in logarithmic time.
)

Container	            Key Features	                                When to Use

set	                    Stores unique sorted elements	                Need a sorted collection with no duplicates
multiset	            stores sorted elements but allows duplicates	Need sorted order and duplicates allowed
map	                    Stores key-value pairs, unique keys	            Need fast lookups with sorted keys
multimap	            Key-value pairs, allows duplicate keys	        Need sorted keys with possible duplicates

Time complexity 

    Search: O(log n)
    Insert: O(log n)
    Erase: O(log n)

1.3 Unordered Containers

*They store elements in no particular order but allow very fast average search using a hash table*

Container	            Key Features	                                    When to Use
unordered_set	        Unique elements, no order, hash-based lookup	    Need fastest possible lookups, no duplicates
unordered_multiset      Allows duplicates, hash-based	                    Fast lookup with duplicates allowed
unordered_map	        Key-value pairs, unique keys, hash-based	        Fast key lookups
unordered_multimap      Key-value pairs, duplicates allowed, hash-based	    Fast key lookups with duplicates

Time complexity 

    Average search: O(1)
    Worst case: O(n) (if hash collisions are bad)
    Insert: O(1) average
