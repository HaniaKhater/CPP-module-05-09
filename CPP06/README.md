## CPP06 - C++ casts

*(Each cast type can only be used in one exercice)*

### ex00: Conversion of scalar types
Create a program named "convert" that takes two parameters, an input string and an output string, and converts the input string to a float and then to an int before writing it to the output string. If the input string is not a valid scalar type or if it represents a value that cannot be represented as an int, the program should write "impossible" to the output string (`+inf`, `-inf`, & `nan` should also be managed).
> In this exercise, we need to convert a scalar type from one type to another. A static cast is the most appropriate cast to use in this situation. It is a compile-time cast. Since we are casting from a float to an int, a static cast can be used to check that the float can be safely represented as an integer. If it cannot be represented as an integer, the static cast will throw an exception. 

### ex01: Serialization
Create a program that takes a pointer to a Data structure, serializes it into an array of chars, and then deserializes it back to the original structure. The Data structure contains three members: a string, an integer, and a string array of 8 chars.
> In this exercise, we need to convert a struct object into an array of bytes and then back into the original struct object. A reinterpret cast is the most appropriate cast to use in this situation. It is an unsafe cast that simply changes the type of the object without changing the underlying bits. Since we need to convert a struct object into an array of bytes and back again, a reinterpret cast can be used to treat the struct object as an array of bytes and then back again.

### ex02: Identify real type
Create a program that takes a pointer to a Base class, identifies the real type of the object pointed to by the pointer, and then displays the appropriate message. The program should handle three derived classes of the Base class: A, B, and C.
> In this exercise, we need to identify the real type of an object pointed to by a base class pointer. A dynamic cast is the most appropriate cast to use in this situation. It is a runtime cast that is used when we need to determine the real type of an object pointed to by a base class pointer at runtime. Since we need to identify the real type of an object pointed to by a Base class pointer, a dynamic cast can be used to safely cast the pointer to a derived class pointer and then check whether the cast was successful or not. If the cast is successful, we can use the derived class pointer to identify the real type of the object. If the cast is not successful, it means that the object pointed to by the base class pointer is not of the derived class type.
