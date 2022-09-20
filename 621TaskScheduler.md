- Method 1 - maxHeap
```javascript
/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
class MaxHeap {
    constructor () {
        this.heap = [];
    }

    insert (val) {
        this.heap.push(val);
        
        let index = this.heap.length - 1;
        
        while (index > 0) {
            const parent = Math.floor((index - 1) / 2);
            
            if (this.heap[parent] < this.heap[index]) {
                const tempValue = this.heap[parent];
                this.heap[parent] = this.heap[index];
                this.heap[index] = tempValue;
                
                index = parent;
            } else {
                break;
            }
        }
    }

    heapPop () {
        let heapSize = this.getHeapSize();
        const tempValue = this.heap[heapSize - 1];
        this.heap[heapSize - 1] = this.heap[0];
        this.heap[0] = tempValue;
        const maxValue = this.heap.pop();
        heapSize = this.getHeapSize();
        
        let index = 0;
        let left = 2 * index + 1;
        let right = 2 * index + 1;
        
        while (left < heapSize) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            const maxChildIndex = right < heapSize && this.heap[left] < this.heap[right] ? right : left;
            
            if (this.heap[maxChildIndex] > this.heap[index]) {
                const tempValue = this.heap[maxChildIndex];
                this.heap[maxChildIndex] = this.heap[index];
                this.heap[index] = tempValue;
                
                index = maxChildIndex;
            } else {
                break;
            }
        }
        
        
        return maxValue;
    }

    getHeapSize () {
        return this.heap.length;
    }
}

var leastInterval = function(tasks, n) {
    const taskCountMapper = {};
    const queue = [];
    let timer = 0;
    
    for (let task of tasks) {
        taskCountMapper[task] = (taskCountMapper[task] || 0)+1;
    }
    
    const maxHeap = new MaxHeap();
    
    // Initialize max heap
    Object.values(taskCountMapper).forEach((count) => {
        maxHeap.insert(count);
    })
    
    
    while (maxHeap.getHeapSize() || queue.length) {
        timer++;
        
        const elementCount = maxHeap.heapPop();
        
        if (!!elementCount && elementCount - 1 > 0) {
            // we store [count, dueTime] into the queue
            queue.push([elementCount - 1, timer+n]);
        }
        
        if (queue[0] && queue[0][1] <= timer) {
            const dueTask = queue.shift();
            maxHeap.insert(dueTask[0])
        }
    }
    
    return timer;
};
```
