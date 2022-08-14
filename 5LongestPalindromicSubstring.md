- Method 1
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length <= 1) return s;
    
    let maxLength = 0;
    let center = 1;
    
    function getLongPalindrome (str, i, j) {
        if (str[i] !== str[j]) return 0;
        
        while (str[i] === str[j] && i >= 0 && j < str.length) {
            i--;
            j++;
        }
        
        const left = i+1;
        const right = j-1;
    
        return right - left + 1;
    }
    
    for (let i = 1; i < s.length; i++) {
        let lengthOdd = getLongPalindrome(s, i, i);
        let lengthEven = getLongPalindrome(s, i-1, i);
        
        let longerLength = Math.max(lengthOdd, lengthEven)
        
        if (longerLength > maxLength) {
            maxLength = longerLength;
            center = i;
        }
    }
    
    const leftEnd = center - Math.floor(maxLength / 2);
    const rightEnd = maxLength % 2 === 0
        ? center + Math.floor(maxLength/2) - 1
        : center + Math.floor(maxLength/2);
    
    return s.substring(leftEnd, rightEnd+1);
};
```
