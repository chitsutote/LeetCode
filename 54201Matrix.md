- Method 1 - Dynamic Programming
```javascript
/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
    const m = mat.length;
    const n = mat[0].length;
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    
    // Do left-up first
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] === 0) continue;
            const top = i - 1 < 0
                ? Infinity
                : dp[i-1][j]
            const left = j - 1 < 0
                ? Infinity
                : dp[i][j-1]
            
            dp[i][j] = 1 + Math.min(top, left);
        }
    }
    
    // do bottom right
    for (let i = m-1; i >= 0; i--) {
        for (let j = n-1; j >= 0; j--) {
            if (mat[i][j] === 0) continue;
            const right = j+1 >= n
                ? Infinity
                : dp[i][j+1];
            const bottom = i+1 >= m
                ? Infinity
                : dp[i+1][j];
            
            dp[i][j] = Math.min(dp[i][j], 1 + Math.min(right, bottom));
        }
    }
    
    return dp;
};
```
