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

- Method 2 - min heap
```javascript
/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
class Heap {
    constructor () {
        this.data = []
    }
    
    getDistanceOfPoint (index) {
        return this.data[index][0]
    }
    
    insert (val) {
        this.data.push(val);
        let index = this.data.length - 1;
        
        // do heapify
        while (index > 0) {
            const parent = Math.floor((index - 1)/2);
            
            if (this.getDistanceOfPoint(parent) > this.getDistanceOfPoint(index)) {
                const temp = this.data[parent];
                this.data[parent] = this.data[index];
                this.data[index] = temp;
                
                index = parent;
            } else {
                break;
            }
        }
    }
    
    heapPop() {
        let dataSize = this.data.length;
        const minValue = this.data[0];
        const temp = this.data.at(-1);
        this.data[dataSize - 1] = this.data[0];
        this.data[0] = temp;
        this.data.pop();
        dataSize = this.data.length;
        
        let index = 0;
        
        // if there is no left child, then certainly no right child, then no need to check child node
        while (2*index + 1 < dataSize) {
            const left = 2*index + 1;
            const right = 2*index + 2;
            
            const minChildIndex = right < dataSize && this.getDistanceOfPoint(left) > this.getDistanceOfPoint(right) ? right : left;
            
            if (this.getDistanceOfPoint(minChildIndex) < this.getDistanceOfPoint(index)) {
                const tempValue = this.data[minChildIndex];
                this.data[minChildIndex] = this.data[index];
                this.data[index] = tempValue;
            
                // update index
                index = minChildIndex;
            } else {
                break;
            }
        }
        
        return minValue;
    }
}
var kClosest = function(points, k) {
    const minHeap = new Heap();
    const result = [];
    
    // Build the min heap
    for (let [x, y] of points) {
        const distance = Math.pow(x, 2) + Math.pow(y, 2);
        minHeap.insert([distance, x, y]);
    }
    
    for (let i = k; i > 0; i--) {
        const [distance, x, y] = minHeap.heapPop();
        result.push([x, y]);
    }
    
    return result;
};
```
