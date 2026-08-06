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
 //do it using middle half 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       //coz slow is at middle 
       ListNode* head1=slow;
       ListNode* temp=head1;
        ListNode* prev=NULL;
        while(temp!=NULL){
            temp=head1->next;
            head1->next=prev;
            prev=head1;
            head1=temp;
        }
        while(prev!=NULL && head!=NULL){
            if(prev->val!=head->val)return 0;
            prev=prev->next;
            head=head->next;
        }


       /*stack<int>st;
       ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        while(head!=NULL){
            if(head->val!=st.top())return 0;
            head=head->next;
            st.pop();
        }*/

        return 1;
    }
};