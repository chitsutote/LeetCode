- Recursion
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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (!root) return null
    
    const left = root.left;
    const right = root.right;
    
    root.left = invertTree(right);
    root.right = invertTree(left);
    
    return root
};
```

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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    const stack = [root];
    
    while (stack.length) {
        const node = stack.pop();
        if (node !== null) {
            const left = node.left;
            const right = node.right;
        
            node.right = left;
            node.left = right;
            
            if (node.left) {
                stack.push(node.left);
            }
            
            if (node.right) {
                stack.push(node.right);
            } 
        }
        
    }
    
    return root
};
```

- BFS
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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    const queue = [root];
    
    while (queue.length) {
        const node = queue.shift();
        if (node !== null) {
            const left = node.left;
            const right = node.right;
        
            node.right = left;
            node.left = right;
            
            if (node.left) {
                queue.push(node.left);
            }
            
            if (node.right) {
                queue.push(node.right);
            } 
        }
        
    }
    
    return root
};
```
