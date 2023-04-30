# PmergeMe

PmergeMe is a program that sorts a list of numbers by using a parallel merge-insertion algorithm. It takes a list of numbers as input and outputs the sorted list followed by the time it took to sort when using a vector as opposed to a double ended que.

## Implementation details

The program uses a parallel merge-insertion algorithm to sort the list of numbers. The input list is first split into pairs, and each pair is sorted using insertion sort. Then, pairs of pairs are merged in parallel until the whole list is sorted.
 The implementation is uses two identical functions: `MergeInsertVector` and `MergeInsertDeque`, which sort the list using a vector and a deque, to compare the sorting algorithm's performance on different containers for inputs of different sizes. .
 
The program also includes a `Parse` function, which parses the input arguments and converts them to integers.

![image](https://media.geeksforgeeks.org/wp-content/uploads/20210923131151/divideKdrawio3.png)

## Error management

Each of the following error cases throws its own exception as to have specific error messages:

* No input or just one number
* Non-digit input
* Negative numbers (not supposed to handle)
* Decimal numbers
* Outside of int limits
* Already sorted


## Example

```
$ ./PmergeMe 9 3 7 5 8 6 4 2
Before : 9 3 7 5 8 6 4 2 
After  : 2 3 4 5 6 7 8 9 
Time to process a range of 8 elements with std::vector : 59 microseconds
After  : 2 3 4 5 6 7 8 9 
Time to process a range of 8 elements with std::deque : 68 microseconds
```

You can also generate large amount of random numbers with the following command
```
$ ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before : 41358 39735 25759 43869 63097 33946 [...]After  : 89 101 145 192 235 236 [...]
Time to process a range of 3000 elements with std::vector : 2455 microseconds
After  : 89 101 145 192 235 236 [...]
Time to process a range of 3000 elements with std::deque : 6642 microseconds
```

