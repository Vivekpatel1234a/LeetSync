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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* dummy=new ListNode(-1);
        int prev=-101;
        ListNode* move=dummy;
        while(temp!=NULL){
            if(temp->val==prev || (temp->next &&  temp->val==temp->next->val)){
                prev=temp->val;
                temp=temp->next;
            }
            else{
                move->next=temp;
                move=temp;
                //prev=temp->val;
                temp=temp->next;

            }
        }
        move->next=NULL;
        return dummy->next;
    }
};
/*
Approach: Traverse the sorted list; if duplicates are found, skip the entire duplicate group and connect the previous unique node directly to the next different node. If the node is unique, simply move prev forward.


class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
ListNode* dummy = new ListNode(-1);
dummy->next = head;

```
    ListNode* prev = dummy;
    ListNode* temp = head;

    while (temp != NULL) {

        // Check if current value is duplicated
        if (temp->next != NULL &&
            temp->val == temp->next->val) {

            // Skip all nodes with this duplicate value
            while (temp->next != NULL &&
                   temp->val == temp->next->val) {
                temp = temp->next;
            }

            // Remove the complete duplicate group
            prev->next = temp->next;
        }
        else {
            // Current node is unique
            prev = prev->next;
        }

        temp = temp->next;
    }

    return dummy->next;
}
```

};

*/