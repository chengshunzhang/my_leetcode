There are two ways:  
1. Find the prefix of first two strings and afterwards, find the prefix of currently found prefix and the next string in strs array. Whenever the prefix is empty, return empty string.  
2. For each character in the first string, traverse the whole array to check whether all the strings have the common character. If yes, append it to the result.
