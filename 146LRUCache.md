- Method 1 - Doulbly linked list/hash map
```javascript
/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.map = new Map();
    this.leastUsed = {};
    this.mostUsed = {};
    
    this.leastUsed.right = this.mostUsed;
    this.mostUsed.left = this.leastUsed;
    
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.map.has(key)) {
        const node = this.map.get(key);
        node.right.left = node.left;
        node.left.right = node.right;
        node.left = this.mostUsed.left;
        node.right = this.mostUsed;
        this.mostUsed.left.right = node;
        this.mostUsed.left = node;
        
        return node.value;
    } else {
        return -1;
    }
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    const newNode = {
        key,
        
        value,
        right: this.mostUsed,
    }
    
    if (this.map.has(key)) {
        const oldNode = this.map.get(key);
        const oldLeftNode = oldNode.left;
        const oldRightNode = oldNode.right;

        // update nodes linking relations
        oldLeftNode.right = oldRightNode;
        oldRightNode.left = oldLeftNode;
    }
    
    this.map.set(key, newNode)
    
    const prevMostUsed = this.mostUsed.left;

    prevMostUsed.right = newNode;
    this.mostUsed.left = newNode;
    newNode.left = prevMostUsed;
    
    if (this.map.size > this.capacity) {
        this.map.delete(this.leastUsed.right.key);
       
        this.leastUsed.right = this.leastUsed.right.right;
        this.leastUsed.right.left = this.leastUsed;
    } 
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
