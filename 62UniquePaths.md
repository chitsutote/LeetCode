- Method 1 - Dynamic programming
```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    const dp = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    dp[m-1][n-1] = 1;
    
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            // NOTE: skip the bottom right element
            if (i === m - 1 && j === n - 1) continue
            const right = j + 1 >= n ? 0 : dp[i][j+1];
            const down = i + 1 >= m ? 0 : dp[i+1][j];
            dp[i][j] = right + down;
        }
    }
    
    return dp[0][0];
};
```
