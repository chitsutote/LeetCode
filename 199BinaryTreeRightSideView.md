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
 * @return {number[]}
 */
var rightSideView = function(root) {
    const queue = [root];
    const result = [];
    
    let queueLength = queue.length;
    while (queueLength) {
        for (let i = 0; i < queueLength; i++) {
            const node = queue.shift();
            if (node) {
                if (i === queueLength - 1) {
                    result.push(node.val);
                }

                if (node.left) queue.push(node.left);
                if (node.right) queue.push(node.right);
            }
        }
        
        queueLength = queue.length;
    }
    
    return result;
};
```
