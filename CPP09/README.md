## CPP09 - Containers

*(Each container type can only be used in in one exercice)*

#### ex00: Bitcoin Exchange
The most appropriate container to use would be an associative container such as a map or unordered_map. This is because the program needs to efficiently search for the exchange rate of a particular date, and associative containers provide fast lookup times based on keys.
#### ex01: Reverse Polish Notation
The most appropriate container to use would be a stack. This is because reverse Polish notation is a stack-based calculation method, where operators are applied to the top elements of the stack, and the result is pushed back onto the stack. Thus, a stack container is the most natural fit for this exercise.
#### ex02: PmergeMe
the most appropriate containers to use would be a vector and a deque. This is because the merge-insertion sort algorithm requires a data structure that can be efficiently sorted, such as a vector, and a data structure that can efficiently insert elements at both ends, such as a deque. By using both containers, we can take advantage of their respective strengths to implement the algorithm efficiently.
