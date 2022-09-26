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
