REVERSE POLISH NOTATION

1 - Parse:
     a -> non digits or op
     b -> each sep by a space
     c -> count nb & operators
     d -> Save all in a fullStack
2 - Loop through it and Live calculations:
     a -> when number   -> save numbers into a nbStack
     b -> when operator -> pop first two
                        -> calculate
                        -> push result

If more than 1 left -> incorrect format
( should be predicted in parsing by just in case?)

----------------- Examples -----------------

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22