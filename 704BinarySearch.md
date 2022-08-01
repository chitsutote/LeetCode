- Method 1
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    const length = nums.length
    let right = length;
    let left = 0;
    let startIndex = Math.floor(length/ 2);
    
    if (nums.length === 1 && nums[0] === target) return 0
    
    while (startIndex !== 0 || startIndex !== length - 1) {
        if (
            nums[startIndex] !== target
            && (
                startIndex === left
                || startIndex === right
                || (right - left === 1)
            )
        ) {
            return -1;
        } else if (nums[startIndex] > target) {
            right = startIndex;
            startIndex = Math.floor(((left + startIndex)/2));
        } else if (nums[startIndex] < target) {
            // move right
            left = startIndex;
            startIndex = Math.floor(((startIndex + right)/ 2));
        }  else if (nums[startIndex] === target) {
            return startIndex;
        }
     }
    
    
    return -1;
};
```
