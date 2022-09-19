- Method 1
```javascript
/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) {
    return points.sort(([x1, y1], [x2, y2]) => (Math.pow(x1, 2) + Math.pow(y1, 2)) - (Math.pow(x2, 2) + Math.pow(y2, 2))).slice(0, k);
};
```
