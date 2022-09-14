- Method 1
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if (!head) return head;
    
    const stack = [];
    while (head) {
        stack.push(head);
        head = head.next;
    }
    
    const tail = stack.pop();
    const root = new ListNode(tail.val);
    let cur = root;
    
    while (stack.length) {
        const node = stack.pop();
        cur.next = new ListNode(node.val);
        cur = cur.next;
    }
    
    return root;
};
```
