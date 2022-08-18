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

- Method 2
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let center = Math.floor(nums.length / 2);
    let left = -1;
    let right = nums.length;
    
    // early return will make runtime shorter
    // if (nums.length === 1 && nums[0] === target) return 0;
    
    while ((right - left) > 1 && (left !== center || right !== center)) {
        if (nums[center] === target) {
            return center;
        } else if (nums[center] > target) {
            right = center;
        } else if (nums[center] < target) {
            left = center;      
        }
        
        center = Math.floor((right + left)/2);
    }
    
    return -1
};
```
