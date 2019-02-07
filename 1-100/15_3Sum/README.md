### Two pointers  
Sort the array, from small to large.  
Iterate over the array, if the sum of first three elements is larger than 0, break; if the sum of first and last two elements is smaller than 0, continue.  
In general, let `target = -nums[i]`, `left = i + 1` and `right = size - 1`. Check whether `nums[left] + nums[right] == target`. If yes, push the three elements to result. Increment the left pointer until a new value, decrement right pointer until a new value; if the sum is smaller than target, `left++`; if the sum is larger than target, `right--`.  
At last, while `nums[i] == nums[i + 1]`, `i++`.
