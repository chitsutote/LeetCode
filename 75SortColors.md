- Counting Sort
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let red = 0;
    let white = 0;
    let blue = 0;
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) red++;
        if (nums[i] === 1) white++;
        if (nums[i] === 2) blue++;
    }
    
    for (let i = 0; i < nums.length; i++) {
        if (red !== 0) {
            nums[i] = 0;
            red--;
        } else if (white !== 0) {
            nums[i] = 1;
            white--;
        } else {
            nums[i] = 2;
            blue--;
        }
    }
};
```

- Two pointer
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    let index = 0;
    
    // when we find every 2, we move right boundary
    // when we find every 0, we move left boundary
    // if the value of current index is 2, we move exchange the value with right boundary and hold the index
    // otherwise, we move index forward
    while (index <= right) {
        switch (nums[index]) {
            case 0: {
                [nums[left], nums[index]] = [nums[index], nums[left]];
                left++;
                index++;
                break;
            }
            case 1: {
                index++;
                break;
            }
            case 2: {
                [nums[right], nums[index]] = [nums[index], nums[right]];
                right--;
                break;
            }
        }
    }
};
```
