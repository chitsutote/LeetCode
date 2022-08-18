- Method 1: thought should be correct, but will get TLE
  - In set part: overhead of initialize array is too high
  - In get part: time complexity of filter is O(n), seems too high for this question
```javascript

var TimeMap = function() {
    this.keyStampMap = {};
    this.keyValueMap = {};
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function(key, value, timestamp) {
    this.keyStampMap[`${key}${timestamp}`] = value;
    this.keyValueMap[key] = [...(this.keyValueMap[key] || []), { value, stamp: timestamp }]
    
    return null;
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function(key, timestamp) {
    const certainValue = this.keyStampMap[`${key}${timestamp}`]
    
    if (certainValue) {
        return certainValue
    } else {
        const seriesData = this.keyValueMap[key] || []
        const qualifiedData = seriesData
            .filter((data) => data.stamp <= timestamp)
        
        return qualifiedData[qualifiedData.length - 1]?.value || ""
    }
};
```

- Method 1 Improved - using binary search
```javascript
var TimeMap = function() {
    this.keyStampMap = {};
    this.keyValueMap = {};
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function(key, value, timestamp) {
    // I was using this way, but initial an array with spread operator is too high when it is larger dataset. As a result, I'll get TLE
    // this.keyValueMap[key] = [...(this.keyValueMap[key] || []), { value, stamp: timestamp }]
    if (this.keyValueMap[key]) {
        this.keyValueMap[key].push({ value, stamp: timestamp })
    } else {
        this.keyValueMap[key] = [{ value, stamp: timestamp }]
    }
       
    return null;
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function(key, timestamp) {
    const seriesData = this.keyValueMap[key] || []
    const index = seriesData.binarySearch(timestamp)
        
    return seriesData[index]?.value ?? "";
    
};

Array.prototype.binarySearch = function (target) {
    let left = 0;
    let right = this.length -1;
    let center = Math.floor((left+right) / 2);
    
    while (right >= left) {
        if (this[center]?.stamp === target) {
            return center;    
        } else if (this[center]?.stamp > target) {
            right = center - 1;
        } else if (this[center]?.stamp < target) {
            left = center + 1;
        }
        
        center = Math.floor((left+right) / 2);
    }
    
    return left - 1;
}
/** 
 * Your TimeMap object will be instantiated and called as such:
 * var obj = new TimeMap()
 * obj.set(key,value,timestamp)
 * var param_2 = obj.get(key,timestamp)
 */
```
