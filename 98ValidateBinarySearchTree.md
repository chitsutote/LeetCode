- Method 1
```javascrpt
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
var isValidBST = function(root) {
    
    function validate (upperBound, lowerBound, node) {
        if (!node) return true;
        
        if (node.val <= lowerBound || node.val >= upperBound) return false;
        
        const left = validate(node.val, lowerBound, node.left);
        const right = validate(upperBound, node.val, node.right);
        
        return left && right;
    }
    
    return validate(Infinity, -Infinity, root);
};
```

- Method 2 inorder traversal
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
// inorder traversal will be like left -> root -> right
var isValidBST = function(root) {
    let prevNode
    
    function inOrder (node) {
        if (!node) return true;
        
        if (!inOrder(node.left)) return false;

        if (!!prevNode && prevNode.val >= node.val) return false;
        
        prevNode = node;
        
        return inOrder(node.right);
    }
    
    return inOrder(root);
};
```
