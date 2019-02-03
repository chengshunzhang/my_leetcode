Scan the string and use a hashmap to map each character to the position in string. `start` denotes the starting position of current no-repeating-character substring.  
Each time in iteration, check whether this character appeared after or at the start position. If yes, calculate the current substring length and update the start position to be the position of this character + 1. If current length is larger than maximum length, update maximum length.  
At last, return either maximum length or the current length.  

### optimize  
We can always use an array of length 256 when dealing with characters and it's usually faster than hashmap.
