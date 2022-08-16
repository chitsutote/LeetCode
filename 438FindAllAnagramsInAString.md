- Brute Force - TLE
```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    
    function sortString (str) {
        return str.split('').sort((a, b) => {
            if (a > b) return 1;
            if (a < b) return -1;
            return 0;
        }).join('');
    }

    const result = [];
    for (let i = 0; i < s.length - p.length+1; i++) {
        const substring = sortString(s.substring(i, i+p.length))
        sortedP = sortString(p);
        
        if (substring === sortedP) {
            result.push(i)
        }
    }
    
    return result
};
```

- Brute Force - solution is correct, somehow it will get TLE

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    const mapper = {};
    const result = [];
    for (let i = 0; i < p.length; i++) {
        if (mapper[p[i]] === undefined) {
            mapper[p[i]] = 1;
        } else {
            mapper[p[i]] = mapper[p[i]] + 1;
        }
    }
    
    for (let i = 0; i < s.length - p.length+1; i++) {
        const tempMapper = {...mapper};
        let done = true;
        
        for (let j = i; j < i + p.length; j++) {
            
            if (tempMapper[s[j]] === undefined) {
                done = false;
                break;
            }
            
            tempMapper[s[j]] -= 1;
            
            if (tempMapper[s[j]] < 0) {
                done = false;
                break;
            }    
        }
        
        if (done) {
            result.push(i);
        }
    }
    
    return result;
};
```

- Sliding Window
```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
    const mapper = {};
    const result = [];
    for (let i = 0; i < p.length; i++) {
        mapper[p[i]] = (mapper[p[i]] || 0) + 1
    }
    
    const windowMapper = {};
    let left = 0;
    
    for (let i = 0; i < s.length; i++) {
        const length = i - left + 1;
        windowMapper[s[i]] = (windowMapper[s[i]] || 0) + 1;
        
        if (length >= p.length) {
	    // adjust the window has the same size with p string
            if (length > p.length) {
                windowMapper[s[left]] -= 1;
                left++;
            }
            
            const isEqual = Object.keys(windowMapper)
                    .map((key) => ({ key, value: windowMapper[key] }))
		    // ignore 0 count to get the current mapper
                    .filter(({ value }) => value !== 0)
		    // check current mapper is as same as targt mapper
                    .every(({ key, value }) => value === mapper[key])
            if (isEqual) {
                result.push(left);
            }
        }
    }
    
    return result;
};
```
