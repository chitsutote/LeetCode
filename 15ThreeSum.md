- Two pointer: turn the question into 2 sum thinking
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const result = [];
    const sortedNums = nums.sort((a, b) => a - b);
    const used = {};
    
    for (let i = 0; i < nums.length; i++) {
	// if the number is used, no need to consider the same number after it
        if (used[sortedNums[i]]) {
            continue;
        }
        
        const targetValue = 0 - sortedNums[i];
        let start = i + 1;
        let end = nums.length -1;
        const usedMiddle = {};
        
        while(end > start) {
	    // if the number is used, no need to consider the same number after it
            if (usedMiddle[sortedNums[start]]) {
                start++;
            } else if ((sortedNums[start] + sortedNums[end]) > targetValue) {
                end--;
            } else if ((sortedNums[start] + sortedNums[end]) < targetValue) {
                start++;           
            } else {
                usedMiddle[sortedNums[start]] = 1;
                result.push([sortedNums[i], sortedNums[start], sortedNums[end]]);
                start++;
            }
        }
        
        used[sortedNums[i]] = 1;
    }
    
    return result;
};
```
