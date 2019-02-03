### Two nested iterations  
Special case: `numRows = 1`, just return the original string.  
Generally, calculate the period and it is easy to get `T = 2 * numRows - 2`.  
  
Outer iteration iterates over rows, i.e., "read" the converted string line by line.  
Inner iteration: pointer j initially points to the starting character of this row and increments by period T.  
1. For 1st and last row, each time just add the current character to result.  
2. For 2nd to last - 1 rows, each time we need to add 2 characters to result. One is just `s[j]`, another one is  
`s[j + T - 2 * i]`.  
Always remember to check boundary.
