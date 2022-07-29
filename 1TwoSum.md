- brute force
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size() -2; i++) {
            for (int j = i + 1; j < nums.size()-1; j++) {
                if ((nums[i] + nums[j] === target)) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};

```
- Using hash map
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> otherHalf;
        
        // establish needed difference for each element
        for (int i = 0; i <= nums.size() -1; i++) {
            otherHalf[target - nums[i]] = i;
        }
        
        for (int i = 0; i <= nums.size() -1; i++) {
            int index = otherHalf[nums[i]];
            
            // skip itself
            // 1. if target is 0 and both element are 0 (if element is not found, map will return 0)
            // 2. if find difference in map (index > 0)
            if (
              index != i &&
              ((nums[index] == 0 && nums[i] == 0) || (index > 0))
            ) {
                ans.push_back(i);
                ans.push_back(index);
                break;
            }
        }
        
        return ans;
    }
};
```



