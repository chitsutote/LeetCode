- Method 1
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    if (s.length === 1) return 1;
    
    let maxLength = 0;
    let hasOdd = false;
    const charCount = {};
    
    for (let i = 0; i < s.length; i++) {
        charCount[s[i]] = charCount[s[i]] === undefined
            ? 1    
            : charCount[s[i]] + 1;
    }
    
    Object.values(charCount).forEach((count) => {
        maxLength += count % 2 ? count - 1 : count;
        
        if (count % 2) {
            hasOdd = true;
        }
    })
    
    return maxLength + (hasOdd ? 1 : 0);    
};
```
