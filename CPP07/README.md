## CPP07 - Templates

### Exercise 00: Start with a few functions

Create a template function `swap` that exchanges the values of two arguments of any type passed by reference. Create a template function `min` that returns the smallest of two arguments of any type passed by reference. Create a template function `max` that returns the largest of two arguments of any type passed by reference.

### Exercise 01: Iter

Create a template function `iter` that takes in parameters an array of any type and the length of that array, and applies a function received in parameter to each of the elements of the array.

### Exercise 02: Array

Create a template class `Array` that stores N elements of type T. It should have the following member functions:
* `Array<T,N>()`: default constructor that initializes all the elements to their default value.
* `Array<T,N>(Array const &)`: copy constructor.
* `Array<T,N> &operator=(Array const &)`: assignment operator overload.
* `T &operator[](unsigned int const &) const`: operator overload that returns the reference of the element at the given index, with range checking. If the index is out of range, the function should throw an exception.
