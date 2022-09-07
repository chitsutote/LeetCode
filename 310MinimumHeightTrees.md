- Method 1
```javascript
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findMinHeightTrees = function(n, edges) {
    if (!edges.length) return [0];
    
    const indegree = {};
    const queue = [];
    const adjacencyNodes = Array.from({ length: n }, () => []);
    
    for ([p1, p2] of edges) {
        indegree[p1] = (indegree[p1] || 0) + 1;
        indegree[p2] = (indegree[p2] || 0) + 1;
        
        adjacencyNodes[p1].push(p2);
        adjacencyNodes[p2].push(p1);
    }
    
    Object.keys(indegree).forEach((key) => {
        if (indegree[key] === 1) queue.push(key);
    });
    
    const cuttedLeaves = [];
    
    let leftNodesCount = n - cuttedLeaves.length;
    
    while (leftNodesCount > 2) {
        const length = queue.length;
        
        for (let i = 0; i < length; i++) {
            const key = queue.shift();
        
            indegree[key] = indegree[key] - 1;
            cuttedLeaves.push(Number(key));
        
            const list = adjacencyNodes[key];
        
            for (item of list) {
                indegree[item] = indegree[item] - 1;
            
                if (indegree[item] === 1) queue.push(item);
            }
        }
        
        leftNodesCount = n - cuttedLeaves.length;
    }
    
    return Object.keys(indegree).map(key => Number(key)).filter((num) => !cuttedLeaves.includes(num));
};
```

