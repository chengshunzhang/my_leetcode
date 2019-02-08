### Dynamic programming  
dp[i][j] represents whether first i elements of s matches first j elements of p, i.e., s[0, i) matches p[0, j).  
Transition function:  
`dp[i][j] = dp[i - 1][j] && p[j - 1] == '*'` // first i - 1 elements of s matches first j elements of p and jth element of p is *. `||`  
`dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?' || p[j - 1] == '*')` // First i - 1 elements of s matches first j - 1 elements of p and ith element of s matches jth element of p. `||`  
`dp[i][j - 1] && p[j - 1] == '*'` // First i elements of s matches first j - 1 elements of p and jth element of p is *.  

### Faster method  
`StarPos`: the last * position in p.  
`sPos`: the start position in s because of the star.  
`sp` and `pp` are pointers that scan s and p respectively.  
`While(sp < s.size())`  
First check whether the current char in s and p match. If yes, sp++ and pp++.  
If not, check whether current char in p is *. If yes, update the `StarPos` to be pp and `sPos` to be sp. Only pp++. If p ends with *, return true.  
If neither match nor *, check whether `StarPos` is -1. If yes, return false. Otherwise, move pp back to `StarPos + 1` and move sp back to `sPos + 1` and increment `sPos` by 1.  
If `StarPos` is -1, i.e., no * yet, retrun false.  
After reaching the end of s, we need one more step to check whether the left chars in p are all *. If not return false.
