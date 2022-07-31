- Brute Force
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;
        
        string trimedS;
        // 1. only accept alphabetics
        for (int i = 0; i < s.length(); i++) {
            if (
                (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')
                || (tolower(s[i]) >= '0' && tolower(s[i]) <= '9')
            ) {
                char lowerChar = tolower(s[i]);
                
                trimedS = trimedS + lowerChar;
            }
        }
        
        // 2. check is palindrome
        return checkIsPalindrome(trimedS);
    }
    
    bool checkIsPalindrome (string s) {
        int end = s.length() - 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[end]) {
                return false;
            }
            
            end--;
        }
        
        return true;
    }
};
```
But this will cause memory limited exceed, so we use two pointer to scan from both end

- Better way
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 1) return true;
        
        string trimedS;
        int end = s.length() -1;
        int start = 0;
        // 1. only accept alphabetics
        while (end > start) {
            char lowerFront = tolower(s[start]);
            char lowerBack = tolower(s[end]);
            
            if (
                !((lowerFront >= 'a' && lowerFront <= 'z')
                || (lowerFront >= '0' && lowerFront <= '9'))
            ) {
                start++;
                continue;
            }
            
            if (
                !((lowerBack >= 'a' && lowerBack <= 'z')
                || (lowerBack >= '0' && lowerBack <= '9'))
            ) {
                end--;
                continue;
            }
            
            
            if (lowerFront != lowerBack) {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
};
```


