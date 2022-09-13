- Method 1
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const result = [nums];
    const setMap = new Map();
    
    const queue = [nums];
    
    while (queue.length) {
        const set = queue.shift();
        if (!set.length) break;
        
        for (let i = 0; i < set.length; i++) {
            const item = set.filter((num) => num !== set[i]);
            const sortedString = item.sort((a, b) => a - b).join('');
            
            if (!setMap.get(sortedString)) {
                setMap.set(sortedString, 1);
                result.push(item);
                queue.push(item);
            }
        }
    }
    
    return result;
};
```
