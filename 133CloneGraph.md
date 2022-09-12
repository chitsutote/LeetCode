- Method 1 - BFS
```javascript
/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if (!node) return null;
    
    const oldToNewMapper = new Map();
    const clonedNode = new Node(node.val);
    oldToNewMapper.set(node, clonedNode);
    const queue = [node];
    
    while(queue.length) {
        const element = queue.shift();
        const neighbors = element.neighbors;
        
        for (let neighbor of neighbors) {
            if (!oldToNewMapper.has(neighbor)) {
                const clonedElement = new Node(neighbor.val);
                oldToNewMapper.set(neighbor, clonedElement);
                queue.push(neighbor);
            }
            
            oldToNewMapper.get(element).neighbors.push(oldToNewMapper.get(neighbor))
        }
    }
    
    return clonedNode;
};
```
