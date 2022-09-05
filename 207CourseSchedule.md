- NOTE
  - new Array(numCourses).fill([]) it will create the empty array with same address. when you modify any of them, all will have same changes


- Method1 - BFS
```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const adjacencyArray = Array.from({ length: numCourses }, () => []);
    const indegree = new Array(numCourses).fill(0);
    
   
    prerequisites.forEach(([course, preq]) => {
        adjacencyArray[preq].push(course);
        indegree[course]++; 
    })
    
    let count = 0;
    const queue = [];
    
    for (let i = 0; i < numCourses; i++) {
        if (!indegree[i]) queue.push(i);
    }
    
    while (queue.length) {
        const startPoint = queue.shift();
        count++;
        
        for (let ele of adjacencyArray[startPoint]) {
            indegree[ele]--;
            
            if (!indegree[ele]) queue.push(ele);
        }
    }
    
    return count === numCourses;
};
```


# Method 2 - DFS
```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const visitedMap = {}
    const adjacencyMap = Array.from({ length: numCourses }, () => []);
    
    prerequisites.forEach(([course, preq]) => {
        adjacencyMap[preq].push(course);
    })
    
    function dfs (node) {
        if (!adjacencyMap[node].length) return true;
        if (visitedMap[node]) return false;
        
        const adjacency = adjacencyMap[node];
        
        visitedMap[node] = 1;
        for (let ele of adjacency) { 
            if (!dfs(ele)) return false;
        }  
        delete visitedMap[node];
	// Has done iterated all adjacency nodes, so current node is finished.
        adjacencyMap[node] = [];
        
        return true;
    }
    
    for (let i = 0; i < numCourses; i++) {
        if (!dfs(i)) return false
    }
    
    return true;
};
```
