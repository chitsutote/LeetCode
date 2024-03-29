# C++
```cpp
/************************
  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

  You may assume that the array is non-empty and the majority element always exist in the array.

Thought:

Method 1. Sort the array then calculate counts of each element , return the element with the max count.

Caution: Sorting method may be the bottleneck , causing TLE

Method 2. Using Moore's Voting Algorithm

"The Majority element is the element that appears more than  ⌊ n/2 ⌋ times." is described in question,that is to say,everytime when we read the same element as previous one from the nums vector we add up the count with 1 , minus 1 when different element pop up. The count of majority element wont be minused to 0. 

 ************************/


class Solution {
		public:
				int majorityElement(vector<int>& nums) {
						int count = 1 ; 
						int majorIndex = 0;

						for(int i = 1 ; i < nums.size(); i++){
								if(nums[i] == nums[majorIndex]){
										count++;
								}else{
										count --;
										if(count == 0){
												majorIndex = i;
												count = 1;
										}
								}
						}

						return nums[majorIndex];
				}
};
```

# Javascript


```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const sortedNums = nums.sort((a, b) => a-b);
    
    let cur = nums[0];
    let compensate = 0;
    let count = 0;
    let max = {
        ele: nums[0],
        count: 0,
    }
    
    for (let i = 0; i < sortedNums.length; i++) {
        if (sortedNums[i] === cur) {
            count++;     
        }
        
        if (sortedNums[i] !== cur) { 
            count = 1;
            cur = sortedNums[i];
        }
        
        if (count > max.count) {
            max.ele = cur;
            max.count = count;
        }
    }
    
    return max.ele;
};
```
