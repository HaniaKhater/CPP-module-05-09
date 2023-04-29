## **REVERSE POLISH NOTATION (RPN)**

### Parse:
* Identify non-digits or non-matematical operators.
* Make sure each token is seperated by space.
* Count the number of operands and operators to make sure that if there are n operands, there a (n - 1) operators.
* Save all tokens in a fullStack.
### Live calculations:
To evaluate the expression, you need to loop through fullStack:

* When you encounter a number<br>
        1. save it into the nbStack.
* When you encounter an operator<br>
        1. pop the first two numbers from nbStack.<br>
        2. Perform the operation on these two numbers.<br>
        3. Push the result back to the nbStack.
(If there is more than one number left on the nbStack after the loop, the input expression is in an incorrect format)

---
### Examples

*Here are some examples of Reverse Polish Notation expressions:

![Image](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Reverse_Polish_Notation_Stack_Example.jpg/800px-Reverse_Polish_Notation_Stack_Example.jpg?20140514181604)

Input: ["2", "1", "+", "3", "*"]<br>
Output: 9<br>
Explanation: ((2 + 1) * 3) = 9<br>

Input: ["4", "13", "5", "/", "+"]<br>
Output: 6<br>
Explanation: (4 + (13 / 5)) = 6<br>

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]<br>
Output: 22<br>
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 =<br>
((10 * (6 / (12 * -11))) + 17) + 5 =<br>
((10 * (6 / -132)) + 17) + 5 =<br>
((10 * 0) + 17) + 5 =<br>
(0 + 17) + 5 = 17 + 5 = <br>
22
