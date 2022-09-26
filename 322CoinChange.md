- Method 1 - DFS & memorization
```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    const cache = {};
    const sortedCoins = coins.sort((a, b) => b-a);
    
    const findCoin = (leftAmount) => {
        if (leftAmount === 0) return 0;
        
        if (cache[leftAmount] !== undefined) return cache[leftAmount];
        
        let minTimes = Infinity;
        for (let coin of sortedCoins) {
            const newLeftAmount = leftAmount - coin;
            if (newLeftAmount >= 0) {
                minTimes = Math.min(minTimes, 1 + findCoin(newLeftAmount));
            }
        }
        
        cache[leftAmount] = minTimes;
        
        return minTimes;
    }
    
    const result = findCoin(amount);
    
    return result === Infinity ? -1 : result;
};
```

- Method 2 - Dynamic programming
```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    const dp = Array.from({ length: amount + 1 }, () => Infinity);
    dp[0] = 0;
    
    for (let i = 1; i < dp.length; i++) {
        for (let coin of coins) {
            if (i - coin >= 0) {
                dp[i] = Math.min(dp[i], 1 + dp[i - coin])
            }
        }
    }
    
    return dp[amount] === Infinity ? -1 : dp[amount];
};
```
