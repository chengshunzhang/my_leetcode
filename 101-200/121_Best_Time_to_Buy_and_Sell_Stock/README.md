`maxp`: current maximum profit, initialized to 0;  
`min`: current minimum price, initialized to INT_MIN.  
Iterate over the prices array and in each iteration:  
1. If current price is less than `min`, update `min` and continue;  
2. Else, if current price minus `min` is larger than `maxp`, update `maxp`.  
Return maxp.
