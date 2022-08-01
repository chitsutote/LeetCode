# Javascript 
- Method 1
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const sortedS = s.split('').sort().join(" ");
    const sortedT = t.split('').sort().join(" ");
    
    return sortedS === sortedT;
};
```

- Method 2
```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const mapper = {};
    
    if (s.length !== t.length) return false;
    
    for (let i = 0; i < s.length; i++) {
        mapper[s[i]] = (mapper[s[i]] || 0) + 1;
    }
    
    for (let i = 0; i < t.length; i++) {
        if (!mapper[t[i]]) return false;
        
        
        mapper[t[i]] = mapper[t[i]] - 1;
    }
    
    return true;
};
```

# C++
```cpp
/*********************
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

********************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int anagram[25]={0};
        int tmp = 0;
        for(int i = 0 ; i < s.length(); i++){
            tmp = s[i];
            anagram[tmp - 97] +=1;
        }
        tmp = 0;
        for(int j = 0 ; j < t.length();j++){
            tmp = t[j]; 
            anagram[tmp - 97] -=1;
            if(anagram[tmp - 97 ] < 0 ) return false;
        }
        return true;
    }
};
```
