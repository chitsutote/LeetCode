- Method 1 - Backtrack
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    const result = [];
    const map = {};
    
    const calculatePermutation = (level, combination) => {
        if (level === nums.length) {
            result.push(combination);
            
            return;
        }
        
        for (let i = 0; i < nums.length; i++) {
            if (map[nums[i]] === undefined) {
                map[nums[i]] = 1;
                calculatePermutation(level+1, [...combination, nums[i]]);
                delete map[nums[i]];
            }
        }
        
        return;
    }
    
    calculatePermutation(0, []);
    
    return result;
};
```
