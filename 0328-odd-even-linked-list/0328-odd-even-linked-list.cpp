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
    ListNode* oddEvenList(ListNode* head) {
    
    if(head==NULL || head->next==NULL)return head;
    ListNode* temp=head->next->next;
    ListNode* even=new ListNode(head->next->val);
    ListNode* odd= new ListNode(head->val);
    ListNode* et=even;
    ListNode* ot=odd;
    int i=1;
    while(temp!=NULL){
        if(i%2!=0){
            ot->next=new ListNode(temp->val);
            ot=ot->next;
            i=0;
        }
        else{
             et->next=new ListNode(temp->val);
             et=et->next;
             i=1;
        }
    
        temp=temp->next;
    }
    ot->next=even;
return odd;
    }
};