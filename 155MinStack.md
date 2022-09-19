- Method 1
```javascript

var MinStack = function() {
    this.min = Infinity;
    this.stack = [];
    this.lengthMinMapper = {};
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    this.min = Math.min(this.min, val);
    this.stack.push(val);
    this.lengthMinMapper[this.stack.length] = this.min;
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.min = this.stack.length-1 ? this.lengthMinMapper[this.stack.length-1]: Infinity;
    return this.stack.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack[this.stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.lengthMinMapper[this.stack.length];
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```

- Method 2 - two array
```javascript

var MinStack = function() {
    this.stack = [];
    this.min = []
    
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    this.stack.push(val)
    this.min.push(Math.min(val, this.min.at(-1) ?? val));
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    this.stack.pop();
    this.min.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.stack.at(-1);
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.min.at(-1);
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
