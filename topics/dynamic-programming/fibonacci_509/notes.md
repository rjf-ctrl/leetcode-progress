# 509. Fibbonacci Number

The standard recursive solution calls F(a given number) multiple times while finding the F(a greater number).
To avoid rrpeated function calls, dynamic programming concept of ## memoization/ tabulation used: *Store the values of expensive function calls so you dont have to repeat them* So, use a vector to store fib(n) and use the array to calucate fib(n+1);