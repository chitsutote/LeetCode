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
var middleNode = function(head) {
    if (!head.next) return head;
    
    let twoStep = head.next.next;
    
    while (twoStep && twoStep.next) {
        twoStep = twoStep.next.next;
        head = head.next;
    }
    
    return head.next;
};
```
