- Method 1 - BFS
```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    
    const queue = [root];
    const result = [];
    
    let queueLength = queue.length;
    while (queueLength) {
        const sameLevelNode = [];
        for (let i = 0; i < queueLength; i++) {
            const node = queue.shift();
            sameLevelNode.push(node.val);
            
            if (node.left)  queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        
        result.push(sameLevelNode);
        queueLength = queue.length;
    }
    
    return result;
};
```
