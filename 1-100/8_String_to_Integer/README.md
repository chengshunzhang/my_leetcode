Scan the string with `start` pointer.  
1. Consume leading whitespaces.  
2. Check whether there's '+' or '-'. Record the sign.  
3. Iterate over digits. `sum` tracks current sum. Generally each time `sum` multiplies by 10 and add the digit pointed by start. At the first of each iteration, check whether `INT_MAX / sum` is smaller than 10. If so, return `INT_MIN` or `INT_MAX` according to sign. If it's equal to 10, compare the difference between `INT_MAX` and `sum * 10` with current digit. If the difference is smaller than current digit, return accordingly.
