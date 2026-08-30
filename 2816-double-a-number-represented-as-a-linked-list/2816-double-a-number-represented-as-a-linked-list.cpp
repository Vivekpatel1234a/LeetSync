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
        if(head->next==NULL)return head;
        ListNode* prev=NULL;
        while(head!=NULL){
            ListNode* nexxt=head->next;
            head->next=prev;
            prev=head;
            head=nexxt;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head=reverse(head); 
        int c=0;
        ListNode* temp=head;
        while(temp!=NULL){
            int ans=(temp->val)*2+c;
            c=ans/10;
            temp->val=ans%10;
            temp=temp->next;
        }
        head=reverse(head);
        if(c==1){
            ListNode* newnode=new ListNode(1);
            newnode->next=head;
            return newnode;
        }
        return head;
    }
};