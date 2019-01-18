## Segment Tree  
`SegmentTreeNode`:   
&nbsp;`start`: start index;   
&nbsp;`end`: end index;  
&nbsp;`middle`: middle of start and end index;  
&nbsp;`sum`: the sum of element in the array from start to end index inclusive.  
`NumArray` member variables:  
`SegmentTreeNode* root`: the root of the segment tree.  
`vector<int> nums`: an array that records the array elements from input.

### constructor  
If input array is empty, set the root to be NULL. Else, calculate the `sums` array with `sums[i]` recording the sum of the first i elements (`sum[0] = 0`). Recursively call construct method to construct the segment tree.  
The construct method accepts four parameters: SegmentTreeNode, sums array, start index and end index. In construct method, first calculate the middle of current segment, assign the sum attribute with `sums[e + 1] - sums[s]`. Then check whether start index is equal to end index. If so, it is the leaf node and return; else, recurse.  

### update  
Recursively call updateHelper method to update the sum attribute of those segments that this element lies in. Then assign the corresponding element in nums to be the new value.  
In updateHelper method, first check current point. If it is NULL, return; else update the sum of this segment to be `sum - nums[i] + val`. If the position is larger than the middle, update right child; else update the left child.  

### sumRange  
Recursively call sumRangeHelper.  
In sumRangeHelper, first check whethr start and end index are the same as this segment. If so, simply return the sum of this segment. Otherwise, consider three situations:  
1. the range is in left part.  
2. the range is in right part.  
3. the range covers left and right part.
