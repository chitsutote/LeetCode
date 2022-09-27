- Method 1
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    if (nums.length === 1) return false;
    const sum = nums.reduce((prev, cur) => prev + cur, 0);
    
    if (sum % 2 !== 0) return false;
    
    let possibleSum = {0: 0};
    const target = sum/2;
    
    for (let i = 0; i < nums.length; i++) {
        let temp = {};
        Object.values(possibleSum).forEach((ele) => {
            temp[ele] = ele;
            temp[ele+nums[i]] = ele+nums[i];
        });
        possibleSum = temp;
    }
    
    return possibleSum[target] !== undefined;
};
```
