--- Two Pointer
```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */

3 + 2 + 0 -4
3 + 2 + 0 -4 + 2 + 0 - 4
var hasCycle = function(head) {
    if (!head) return false;
    
    let first = head.next;
    let second = head;
    
    if (!first) return false;
    
    while (first && second) {
        if (first === second) return true;
        
        if (!first.next) return false;
        
        first = first.next.next;
        second = second.next;
    }
    
    return false;
};
```
