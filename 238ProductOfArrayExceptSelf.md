- time complexity O(n)
```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const length = nums.length;
    const result = [];
    if (length === 2) return [nums[1], nums[0]];
    
    const leftMultiply = new Array(length).fill(1);
    const rightMultiply = new Array(length).fill(1);
    
    for (let i = length - 1; i >= 0; i--) {
        const previousValue = i + 1 >= length ? 1 : rightMultiply[i+1];
        const prevNum = i + 1 >= length ? 1 : nums[i+1];
        rightMultiply[i] = previousValue * prevNum;
    }
    
    for (let i = 0; i < length; i++) {
        const previousValue = i - 1 < 0 ? 1 : leftMultiply[i-1];
        const prevNum = i - 1 < 0 ? 1 : nums[i-1];
        leftMultiply[i] = previousValue * prevNum;
    }
    
    for (let i = 0; i < length; i++) {
        result.push(leftMultiply[i] * rightMultiply[i]);
    }
    
    return result;
};
```
