- Method 1
```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (
        intervals.length === 0
        || intervals.length === 1
    ) return intervals;
    
    const sortedIntervals = intervals.sort((a, b) => a[0] - b[0]);
    
    const result = [];
    let start = sortedIntervals[0][0];
    let end = sortedIntervals[0][1];
    let overlapped = false;
    let isMergeDone = false;
    result.push(sortedIntervals[0]);
    
    for (let i = 1; i < sortedIntervals.length; i++) {
        const eachIntervalStart = sortedIntervals[i][0];
        const eachIntervalEnd = sortedIntervals[i][1];
        
        if (!overlapped) {
            if (eachIntervalStart <= sortedIntervals[i-1][1]) {
                overlapped = true;
                isMergeDone = false;
                start = Math.min(eachIntervalStart, sortedIntervals[i-1][0]);
                end = Math.max(eachIntervalEnd, sortedIntervals[i-1][1]);
                
                result.pop();
            }   
        } else {
            if (
                eachIntervalStart > sortedIntervals[i-1][1]
                && eachIntervalStart > end
            ) {
                overlapped = false;
                
                // push target element
                if (!isMergeDone) {
                    result.push([start, end]);
                    isMergeDone = true;
                }
            } else {
                end = Math.max(end, eachIntervalEnd);
            }
        }
        
        if (!overlapped) {
            result.push(sortedIntervals[i]);
        }
        
        if (overlapped && i === sortedIntervals.length -1) {
            result.push([start, end]);
        }
    }
    
    return result;
};
```

