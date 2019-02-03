## Basic idea  
Set two pointers `p` and `q` to iterate over two lists. Let carry = 0 originally and in each iteration, calculate `sum = carry + addition`, `add = sum % 10`, `carry = sum / 10`. At last, don't forget to check whether carry is 0. If not, add one more node.  

### Original  
`while(p && q) {...}`, then `while(p) {...}`, then `while(q) {...}`.  

### Avoid code duplication  
`while(p || q) {if(p) {...} if(q) {...} ...}`
