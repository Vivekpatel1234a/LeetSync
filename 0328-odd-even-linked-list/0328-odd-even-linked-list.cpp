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
    ListNode* even=head->next;
    ListNode* odd=head;
    ListNode* et=even;
    ListNode* ot=odd;
    int i=1;
    while(temp!=NULL){
        if(i%2!=0){
            ot->next=temp;
            ot=ot->next;
            i=0;
        }
        else{
             et->next=temp;
             et=et->next;
             i=1;
        }
    
        temp=temp->next;
    }
    et->next=NULL;
    ot->next=even;
return odd;
    }
};