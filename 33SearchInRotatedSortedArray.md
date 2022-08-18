- Method 1: binary search and coordinate system conversion
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    if (nums.length === 1) return nums[0] === target ? 0 :  -1;
    
    // 1. find head and tail
    let head = 0;
    let min = 99999
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < min) {
            min = nums[i];
            head = i;
        }
    }
    
    let tail = head - 1 >= 0 ? head - 1 :nums.length - 1;
    const pivot = nums.length - head;
    
    let left = 0;
    let right = nums.length - 1;
    let center = Math.floor((left + right) / 2);
    
    while (right >= left) {
        const pivotedCenter = (center - pivot) < 0 ? center - pivot + nums.length : center - pivot;
        
        if (nums[pivotedCenter] === target) {
            return pivotedCenter;
        } else if (nums[pivotedCenter] > target) {
            right = center - 1;
        } else if (nums[pivotedCenter] < target) {
            left = center + 1;
        }
        
        center = Math.floor((left+right)/2);
    }
    
    return -1;
};
```
