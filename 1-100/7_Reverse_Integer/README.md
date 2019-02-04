1. Check if the x is INT_MIN. If so, return 0 because reversed INT_MIN is bound to overflow.  
2. Record the sign of x and make x positive.  
3. While loop, each time get the least significant digit of x and current summation multiplies by 10 and add them up. x divided by 10. At the start of each iteration, check whether sum will overflow. This is done by using `INT_MAX / sum`, if it's smaller than 10, overflow occurs.  
Think about whether it is possible to overflow when `INT_MAX / sum` is 10. It's impossible because INT_MAX starts with 2 and ends with 7.
