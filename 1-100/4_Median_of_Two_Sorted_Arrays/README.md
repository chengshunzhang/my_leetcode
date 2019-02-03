## Find Kth element in "merged" arrays  
Use `start1` and `start2` to denote the starting position of each array. The elements before start are discarded as they can't be the Kth element. K indexes from 1.  
1. If 1st array is "empty", i.e., `start1 >= 1st array size`, the Kth element is just the Kth element in 2nd array.
2. If 2nd array is "empty", i.e., `start2 >= 2nd array size`, the Kth element is just the Kth element in 1st array.  
3. In general, compare the (K / 2)th element in two arrays.  
`val1 = nums1[start1 + K / 2 - 1]` and `val2 = nums2[start2 + K / 2 - 1]`  
Discard the K / 2 elements of the array with smaller value. If one array doesn't have K / 2 elements, i.e., `start + K / 2` is larger than the size, we can let `val` be `INT_MAX`. Since we will always discard the K / 2 elements in the other array.  

## Find Median  
For odd number, find the ((m + n + 1) / 2)th element and for even number, find ((m + n) / 2)th and ((m + n) / 2 + 1)th elements and calculate the average.  
To avoid if else, we can always find the ((m + n + 1) / 2)th and ((m + n + 2) / 2)th elements and calculate their average. Because for odd number, they are the same element.
