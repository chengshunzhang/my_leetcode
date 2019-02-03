## Center Expansion  
For each character in the string, use two pointers `left` and `right` to expand leftward and rightward, both starting from the current character.  
1. When `s[left] == s[i]`, `left--`  
2. When `s[right] == s[i]`, `right++`  
(the order of 1 and 2 is changeable)  
3. When `s[left] == s[right]`, `left--, right++`  
Always remember to check the boundary. After the process, if current length is larger than maximum length, update maximum length.  

## Dynamic Programming  
`dp[i][j]`: whether the substring from i to j is a palindrome.  
Transition function: `if(dp[i + 1][j - 1] && s[i] == s[j]) dp[i][j] = true; else dp[i][j] = false`.  
Initialization: Diagonal elements are true since the string with only one character is a palindrome. Upper subdiagonal elements are true if they are the same as their previous character.  
Iterate over length = 3 to string size. In each iteration, iterate over i, i.e., starting position.
