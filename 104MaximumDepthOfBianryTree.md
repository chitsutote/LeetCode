- Method 1 - DFS
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
 * @return {number}
 */
var maxDepth = function(root) {
    let maxDepth = 0;
    
    function dfs (node) {
        if (!node) return 0;
        
        const left = dfs(node.left);
        const right = dfs(node.right);
        
        const depth = Math.max(left, right) + 1;
        maxDepth = Math.max(depth, maxDepth);
        
        return depth;
    }
    
    dfs(root);
    
    return maxDepth; 
};
```
