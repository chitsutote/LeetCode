- Map - because need to reset map, it will get TLE when meets large dataset
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // Question1. Is lowercase and uppercase count as same? Seems not the same
    // Question2. Can repeating symbols, spaces be counted in? Seems symbols and spaces are legit characters in the question
    let count = 0;
    
    let left = 0;
    let maxLength = 0;
    let aphabetMap = {};
    
    
    for(let i = 0; i < s.length; i++) {
        if (aphabetMap[s[i]] !== undefined) {
            const newStartIndex = aphabetMap[s[i]];
            count = i - newStartIndex;
            const clearedMap = Object.keys(aphabetMap)
                .map(key => ({
                    key,
                    value: aphabetMap[key],
                }))
                .filter(({ value }) => value > newStartIndex)
                .reduce((prev, cur) => ({...prev, [cur.key]: cur.value }), {});
            aphabetMap = {
                [s[i]]: i,
                ...clearedMap,
            };
        } else {
            count++;
            maxLength = Math.max(maxLength, count);
            
            
            aphabetMap[s[i]] = i;
        }
    }
    
    return maxLength;
};
```

- Two pointer - move the boundary, we ignore the index of alphabet in the mapper which is out of left bound
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // Question1. Is lowercase and uppercase count as same? Seems not the same
    // Question2. Can repeating symbols, spaces be counted in? Seems symbols and spaces are legit characters in the question
    let maxLength = 0;
    let left = 0;
    let right = 0;
    let mapper = {};
    let count = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (mapper[s[i]] !== undefined) {
            left = Math.max(left, mapper[s[i]] + 1);
            count = i - left + 1;
        } else {
            count++;
        }
        
        mapper[s[i]] = i;
        maxLength = Math.max(maxLength, count);
    }
    
    return maxLength;
};
```
