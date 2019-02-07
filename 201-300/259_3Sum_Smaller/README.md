### Two pointers  
Sort the array. Iterate over each element with index i.  
If the sum of first three elements is larger than target, break.  
Let `left = i + 1` and `right = size - 1`. If the sum is larger than target, right--; if the sum is smaller than target, `result += right - left`.
