- DFS
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
 * @return {boolean}
 */
var isBalanced = function(root) {
    if (!root) return true;
    let result = true;
   
    function getMaxLevel (root) {
        if (!root) return 0;
        
        const leftLevel = getMaxLevel(root.left);
        const rightLevel = getMaxLevel(root.right);
        
        if (Math.abs(leftLevel - rightLevel) > 1) {
            result = false;
            return 0;
        }
        
        return Math.max(leftLevel, rightLevel) + 1
    }
    
    getMaxLevel(root);
    
    return result;
};
```
