- Recursive
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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    if (!preorder.length || !inorder.length) return null;
    
    const root = new TreeNode(preorder[0]);
    const rootPosition = inorder.indexOf(preorder[0]);
    root.left = buildTree(preorder.slice(1, rootPosition+1), inorder.slice(0, rootPosition));
    root.right = buildTree(preorder.slice(rootPosition+1), inorder.slice(rootPosition+1));
    
    return root;
};
```
