```javascript
/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    let cleanStr = '';
    let isPositive = true;
    let result = 0;
    let signedNumber = 0;
    
    for (i = 0; i < s.length; i++) {
        if (cleanStr.length === 0 && s[i] === ' ' && signedNumber < 1) continue;
        if (cleanStr.length === 0 && s[i] === '-') {
            isPositive = false;
            signedNumber++;
            continue;
        }
        
        if (cleanStr.length === 0 && s[i] === '+') {
            signedNumber++;
            continue;
        }
    
        if (cleanStr.length === 0 && signedNumber > 1) break;
        
        if (cleanStr.length === 0 && !('0' <= s[i] && s[i] <= '9')) break;
        if (cleanStr.length && !('0' <= s[i] && s[i] <= '9')) break;
        
        cleanStr += s[i];
    }

    const rawResult = cleanStr.length > 0 ? Number(cleanStr) : 0
    result = isPositive ? rawResult : rawResult * -1;
    
    if (result >= Math.pow(2, 31)) result = Math.pow(2, 31) - 1;
    if (result <= Math.pow(2, 31) * -1) result = -1 * Math.pow(2, 31);
    
    return result;
};
```
