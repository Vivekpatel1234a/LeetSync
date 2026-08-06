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
    int pairSum(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       //coz slow is at middle , ab middle half reverse kr do 
       ListNode* head1=slow;
       ListNode* temp=head1;
        ListNode* prev=NULL;
        while(temp!=NULL){
            temp=head1->next;
            head1->next=prev;
            prev=head1;
            head1=temp;
        }
        //ab head start pr hai and prev jo hai vo reversed part ke start pr hai
        int maxi=0;
        while(head!=NULL && prev!=NULL){
            maxi=max(maxi,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return maxi; 
    }
};