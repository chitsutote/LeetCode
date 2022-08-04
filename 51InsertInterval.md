```javascript
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let newStart = newInterval[0];
    let newEnd = newInterval[1];
    const leftPartition = [];
    const rightPartition = [];

    
    for(let i = 0; i < intervals.length; i++) {
        const [eachIntervalStart, eachIntervalEnd] = intervals[i];
        
        if (eachIntervalEnd < newInterval[0]) {
            leftPartition.push(intervals[i]);
        } else if (newInterval[1] < eachIntervalStart) {
            rightPartition.push(intervals[i]);
        } else {
           
            newStart = Math.min(eachIntervalStart, newStart);
            newEnd = Math.max(eachIntervalEnd, newEnd);
        }
     
    }
    
    return [...leftPartition, [newStart, newEnd], ...rightPartition];
};
```
