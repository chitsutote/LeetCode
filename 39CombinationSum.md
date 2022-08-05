- Backtrace
```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target, index) {
    const result = [];
    
    function backTrace (target, solutionToBe, index) {
        if (target < 0) return;
        
        
        if (target === 0) {
            result.push([...solutionToBe]);
            
            return;
        }
        
        
        for (let i = index; i < candidates.length; i++) {
            solutionToBe.push(candidates[i]);
            backTrace(target - candidates[i], solutionToBe, i);
        
            solutionToBe.pop();
        }
        
        return;
    }
    
    backTrace(target, [], 0);
    
    return result;
};
```
