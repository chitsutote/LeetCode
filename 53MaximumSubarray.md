- Brute Force -> will get TLE
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if (nums.length === 1) return nums[0];
    let maxValue;
    
    for (let i = 0; i < nums.length; i++) {
        let sum = nums[i];
        
        if (sum > maxValue || maxValue === undefined) {
            maxValue = sum;
        }
        for (let j = i+1; j < nums.length; j++) {
            sum += nums[j];
            if (sum > maxValue || maxValue === undefined) {
                maxValue = sum;
            }
        }   
    }
    
    return maxValue;
};
```

-- Method 2 - sliding window
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if (nums.length === 1) return nums[0];
    let maxValue = nums[0];
    let curSum = 0;
    
    // keep accumulate the value until it turns negative, then we find a new start
    for (let i = 0; i < nums.length; i++) {
        if (curSum < 0) curSum = 0;
        curSum += nums[i];
        maxValue = Math.max(curSum, maxValue);
    }
    
    return maxValue;
};
```
