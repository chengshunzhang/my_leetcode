### Recursion  
1. If p is empty, only if s is also empty, they match.  
2. If the size of p is larger than 1 and `p[1]` is *, they match with two cases.First: the char before * matches 0 char in s, so we check whether s matches the substring of p after the *; Second: s is not empty and the char before * matches the first char in s, then we check whether the substring of s from second char mathces p.  
3. Otherwise (the size of p is 1 or the size is larger than 1 but the second char is not *): check whether the first char matches and the substring of s and the substring of p matches.  

  
### Dynamic Programming  
dp[i][j] means the first i chars of s matches the first j chars of p, i.e.,   
s[0, i) matches p[0, j).  
`dp[0][0] = true` because two empty strings match.  
Transition function:  
`dp[i][j] = dp[i - 1][j] && p[j - 1] == '*' && (p[j - 2] == s[i - 1] || p[j - 2] == '.')` // First i - 1 chars of s matches first j chars of p and the jth element of p is * and the char before * is the "same" as ith element of s. `||`  
`dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.')` // First i - 1 chars of s matches first j - 1 chars of p and the jth element of p matches the ith element of s. `||`  
`dp[i][j - 2] && p[j - 1] == '*'` // First i chars of s matches first j - 2 chars of p and jth element of p is *.  
Initialization:  
We can of course initialize the first row and first two columns. But in this problem we can make the code cleaner and initialize dp[0][0] is enough. We can just add condition for i and j in transition function. Notice that the first column is always false, so we can iterate j from 1.
