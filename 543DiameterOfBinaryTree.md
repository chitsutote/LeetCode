- Method 1 - resusive DFS
check each parent node its possible diameter
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
var diameterOfBinaryTree = function(root) {
    if (!root.left && !root.right) return 0;
    let maxLength = 0;
    
    
    function dfs (root) {
        if (!root) return -1;
        
        const left = dfs(root.left) + 1;
        const right = dfs(root.right) + 1;
        
        return Math.max(left, right);
    }
    
    function calculatePath (root) {
        if (!root.right) return 1 + dfs(root.left);
        if (!root.left) return 1 + dfs(root.right);

        const leftMax = dfs(root.left);
        const rightMax = dfs(root.right);

        return leftMax + rightMax + 2;
    }
    
    const queue = [root];
    
    while (queue.length) {
        const node = queue.shift();
        
        maxLength = Math.max(maxLength, calculatePath(node));
        
        if (node.left) queue.push(node.left);
        if (node.right) queue.push(node.right);
    }
    
    return maxLength;
};
```

- Method 2 - DFS
The max route must go from longest left path of left subtree through node to longest right path of right subtree
we record the max route while bottom up
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
var diameterOfBinaryTree = function(root) {
    // if (!root.left && !root.right) return 0;
    let maxLength = 0;


    function dfs (root) {
        if (!root) return 0;

        const left = dfs(root.left);
        const right = dfs(root.right);
        maxLength = Math.max(maxLength, left + right);

        return Math.max(left, right) + 1;
    }

    dfs(root);

    return maxLength;
};
```
