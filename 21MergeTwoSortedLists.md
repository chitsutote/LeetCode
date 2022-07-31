- Iteration
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* cur = new ListNode();
        
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1 -> val > list2->val) {
            head = list2;
            cur = list2;
            list2 = list2 -> next;
        } else {
            head = list1;
            cur = list1;
            list1 = list1 -> next;
        }
       
        // Iterate whole list until one list ends 
        while (list1 && list2) {        
            if (list1 -> val > list2 -> val) {
                cur -> next = list2;
                
                list2 = list2 -> next;
            } else {
                cur -> next = list1;
                
                list1 = list1 -> next;
            }
            
            cur = cur -> next;
        }
        
        // append rest of list if it remains other elements
        if (list1) {
            cur -> next = list1;
        } else if (list2) {
            cur -> next = list2;
        }
        
        return head;
    }
};
```

- Recursion
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {       
        if (!list1) return list2;
        if (!list2) return list1;
        
        
        if (list1 -> val > list2 -> val) {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            
            return list2;
        } else {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            
            return list1;
        }
    }
};
```
