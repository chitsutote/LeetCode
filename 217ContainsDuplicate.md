- map
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const map = {}
    
    for (let i = 0; i < nums.length; i++) {
        const currentValue = map[nums[i]];
        
        if (currentValue) {
           return true; 
        } else {
            map[nums[i]] = 1;
        }  
    }
    
    return false;
};
```

- sort
```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    
    const sortedNums = nums.sort((a, b) => a - b);
     
    for (let i = 1; i < sortedNums.length; i++) {
        if (sortedNums[i] === sortedNums[i-1]) return true;
    }
    
    return false;
};
```


# C++
```cpp
/****************************

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

Thought:
  using STL container "set", 
  traverse all element in the array if the element already in set that means duplicated, return true.
  else return false
  
  
***************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0 ; i < nums.size();i++){
            
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
```
  

