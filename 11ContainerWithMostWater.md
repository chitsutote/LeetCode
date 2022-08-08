- Bruete Force - will TLE in larger dataset
```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let maxArea = 0;
    
    const sortedHeight = height.map((h, index) => ({
        height: h,
        index,
    })).sort((a, b) => a.height - b.height)
    
    for (let i = sortedHeight.length - 1; i > 0; i --) {
        for (let j = i - 1; j >=0; j--) {
            const width = Math.abs(sortedHeight[i].index - sortedHeight[j].index);
        
            maxArea = Math.max(width * sortedHeight[j].height, maxArea);
        }
    }
    
    return maxArea;
};
```

- Two Pointer
```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left = 0;
    let right = height.length - 1;
    
    let lowerBoundary = height[left] > height[right] ? height[right] : height[left];
    let maxArea = lowerBoundary * (height.length -1)
    
    while (left < right) {
        // move the boundary with lower height
        if (height[left] > height[right]) {
            right--;
        } else {
            left++;
        }
        lowerBoundary = height[left] > height[right] ? height[right] : height[left];
        
        maxArea = Math.max(maxArea, lowerBoundary * (right - left))
    }
    
    return maxArea;
};
```
