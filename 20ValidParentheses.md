- Brute force
```cpp
class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        vector<char> eleStack;
        temp.push_back(s[0]);
        
        if (s.length() == 1) return false;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
            
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                eleStack.push_back(s[i]);
                if (i == s.length() -1) {
                    result = false;
                    break;
                }
            } else {
                if (eleStack.size() == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                    result = false;
                    break;
                }
                
                if (eleStack[eleStack.size() - 1] == '(' && s[i] != ')') {
                    result = false;
                    break;
                }
                
                if (eleStack[eleStack.size() - 1] == '{' && s[i] != '}') {
                    result = false;
                    break;
                }
                
                if (eleStack[eleStack.size() - 1] == '[' && s[i] != ']') {
                    result = false;
                    break;
                }
                
                eleStack.pop_back();
            }
        }
        
        
        return !eleStack.size() && result;
    }
};
```

- Better Brute Force
```cpp
class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        vector<char> eleStack;
        eleStack.push_back(s[0]);
        
        if (s.length() == 1) return false;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
            
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                eleStack.push_back(s[i]);
            } else {
                if (eleStack.size() == 0) {
                    result = false;
                    break;
                }
                
                char topEle = eleStack[eleStack.size()-1];
                eleStack.pop_back();
                
                switch(topEle) {
                    case '(': {
                        if(s[i] != ')') {
                            result = false;
                        }
                        break;
                    }
                    case '{': {
                       if(s[i] != '}') {
                           result = false;
                       }
                       break;
                    }
                    case '[': {
                       if(s[i] != ']') {
                           result = false;
                       }
                       break;
                    }
                    default: {
                        result = false;
                        break;
                    }
                }
            }
        }
        
        return !eleStack.size() && result;
    }
};
```

- Method 3
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (s.length % 2 === 1) return false;
    
    const map = {
        '(': ')',
        '{': '}',
        '[': ']',
    }
    
    const stack = [];
    
    for (let ele of s) {
        if (ele === ')' || ele === ']' || ele === '}') {
            const left = stack.pop();
            
            if (map[left] !== ele) return false;
        } else {
            stack.push(ele);
        }
    }
    
    return stack.length ? false : true;
};
```


- NOTE
1. Build more test cases to validate solution.
2. Parentheses must match, so input sring must be divided by 2.
