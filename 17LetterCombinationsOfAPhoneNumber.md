- Method 1 - Backtrack
```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (!digits.length) return [];
    
    const result = [];
    const numberStringMapper = {
        1: '',
        2: 'abc',
        3: 'def',
        4: 'ghi',
        5: 'jkl',
        6: 'mno',
        7: 'pqrs',
        8: 'tuv',
        9: 'wxyz',
    }
    
    const backtrack = (level, tempArr) => {
        if (level === digits.length) {
            result.push(tempArr.join(''));
            return;
        }
        
        const currentDigitString = numberStringMapper[digits[level]];
        
        for (let i = 0; i < currentDigitString.length; i++) {
            backtrack(level+1, [...tempArr, currentDigitString[i]]);
        }
        
        return;
    }
    
    backtrack(0, []);
    
    return result;
};
```
