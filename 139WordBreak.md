- Method 1 - recursive
```javascript
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    const substringResultMapper = {};
    const wordDictMapper = {};
    
    for (let word of wordDict) {
        wordDictMapper[word] = true;
    }
    
    const findMatch = (index, substring) => {
        if (substringResultMapper[substring] !== undefined) {
            return substringResultMapper[substring];
        }
        
        if (!substring.length || wordDictMapper[substring]) {
            return true
        }
        
        for (let word of wordDict) {
            const wordLength = word.length;
            const firstPart = substring.slice(index, wordLength);
            const secondPart = substring.slice(index+wordLength, s.length);
            
            if (wordDictMapper[firstPart] && findMatch(0, secondPart)) {
                substringResultMapper[substring] = true;
                
                return true;
            }
            
        }
            
        substringResultMapper[substring] = false;
        return false;
    }
    
    return findMatch(0, s);
};
```

- Method 2 - Dynamic programming
```javascript
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    const length = s.length;
    const flag = Array.from({ length: length + 1 }, () => false);
    const lookupMapper = {};
    flag[0] = true;
    
    for (let word of wordDict) {
        lookupMapper[word] = true;
    }
    
    for (let i = 0; i < length; i++) {
        if (!flag[i]) continue;
        
        for (let word of wordDict) {
            const wordLength = word.length;
            const endPosition = i + wordLength;
            const substring = s.slice(i, endPosition);
            
            if (endPosition > length) continue;
            
            if (lookupMapper[substring]) {
                flag[endPosition] = true;
            }
        }
    }
    
    return flag[length];
};
```
