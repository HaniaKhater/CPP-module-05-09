## CPP09 - Containers

*(Each container type can only be used in one exercice)*

### ex00: Bitcoin Exchange
Create a program that reads a CSV file representing bitcoin prices over time, and takes another file as input. The program should output the value of a certain amount of bitcoin on a certain date. The value in the input file should be multiplied by the exchange rate according to the date indicated in the database, and if the date used in the input does not exist in the database, the closest previous date contained in the database should be used.
> The most appropriate container to use would be an associative container such as a map or unordered_map. This is because the program needs to efficiently search for the exchange rate of a particular date, and associative containers provide fast lookup times based on keys.

### ex01: Reverse Polish Notation
Create a program named RPN that takes an inverted Polish mathematical expression as an argument, and processes the expression to output the correct result on the standard output. The program should handle operations with these tokens: "+ - / *", and be able to handle errors.
> The most appropriate container to use would be a stack. This is because reverse Polish notation is a stack-based calculation method, where operators are applied to the top elements of the stack, and the result is pushed back onto the stack. Thus, a stack container is the most natural fit for this exercise.

### ex02: PmergeMe
Create a program named PmergeMe that takes a positive integer sequence as an argument and uses a merge-insert sort algorithm to sort the sequence. The program should be able to handle at least 3000 different integers and display information line by line on the standard output.
> The most appropriate containers to use would be a vector and a deque. This is because the merge-insertion sort algorithm requires a data structure that can be efficiently sorted, such as a vector, and a data structure that can efficiently insert elements at both ends, such as a deque. By using both containers, we can take advantage of their respective strengths to implement the algorithm efficiently.
