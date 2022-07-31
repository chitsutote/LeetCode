- Brute Force
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        int maxProfitMade = 0;
        
        for (int i = 0; i < prices.size() - 2; i++) {
            for (int j = i + 1; j < prices.size() - 1; ) {
                int diff = prices[j] - prices[i];
                
                if (diff > maxProfitMade) {
                    maxProfitMade = diff;
                }
            }
        }
        
        
        return maxProfitMade;
    }
};
```
But it will get TLE when there is larger data set

- One Loop version
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        int maxProfitMade = 0;
        int lowestPrice = 9999;
        
	/**
	 * NOTE:
	 *  because the data is time series, we go through each elements and record the lowest price and caculate the profit with each elements.
	*/
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowestPrice) {
                lowestPrice = prices[i];
            }
            
            int diff = prices[i] - lowestPrice;
            
            if (maxProfitMade < diff) {
                maxProfitMade = diff;
            }
            
        }
        
        
        return maxProfitMade;
    }
};

```

