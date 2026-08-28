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

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
      }
      ListNode* temp=slow->next;
      slow->next=NULL;
      temp=reverse(temp);
      ListNode* move=head;
      ListNode* nextmove=NULL;
      
      while(temp!=NULL){
        nextmove=move->next;
        move->next=temp;
        move=temp;
        temp=temp->next;
        move->next=nextmove;
        move=nextmove;
      }

    }
};