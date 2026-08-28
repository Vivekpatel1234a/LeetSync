/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */////////////////OPTIMISE THEM //////////////////
class Solution {
public:

   ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL){
        ListNode* nextnode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;
    }
    return prev;
   }

    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* temp=head;
      ListNode* prev=NULL;
      while(temp!=NULL){
        int sz=k-1;
        ListNode* start=temp;
        while(sz && temp!=NULL){
            temp=temp->next;
            sz--;
        }
        if(temp!=NULL){
            ListNode* nextnode=temp->next;
            temp->next=NULL;
            temp=reverse(start);
            if(head==start)head=temp;
            if(prev)prev->next=temp;
            prev=start;
            start->next=nextnode;
            temp=nextnode;
        }
      }
      return head;

    }
};