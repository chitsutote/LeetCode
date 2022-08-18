- Method 1: Binary Search
```javascript
/**
 * Definition for isBadVersion()
 * 
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let left = 0;
        let right = n+1;
        let center = Math.floor((left+right)/2)
        
        while (right >= left) {
            if (
                isBadVersion(center)
                && !isBadVersion(center-1)
                && isBadVersion(center+1)
            ) {
                return center;
            } else if (!isBadVersion(center)) {
                left = center+1;
            } else {
                right = center-1;
            }
            
            center = Math.floor((left+right)/2)
        }
    };
};
```
