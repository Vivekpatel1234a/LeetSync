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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reversal part
        ListNode* head=l1;
        ListNode* temp=head;
        ListNode* prev=NULL; 
        while(temp!=NULL){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
         l1=prev;


         head=l2;
         temp=head;
         prev=NULL; 
        while(temp!=NULL){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        l2=prev;
        ListNode* ans=new ListNode(0);
        head=ans;
        int c=0;

        
        while(l1!=NULL && l2!=NULL){
            int sum=l1->val+l2->val+c;
            ans->next=new ListNode(sum%10);
            c=sum/10;
            ans=ans->next;
            l1=l1->next;
            l2=l2->next;
            if(l1==NULL){
                while(l2!=NULL){
                    sum=l2->val+c;
                    ans->next=new ListNode(sum%10);
                    ans=ans->next;
                    c=sum/10;
                    l2=l2->next;
                }
            }
            if(l2==NULL){
                while(l1!=NULL){
                    sum=l1->val+c;
                    ans->next=new ListNode(sum%10);
                    ans=ans->next;
                    c=sum/10;
                    l1=l1->next;
                }
            }
        }
        if(c==1)ans->next=new ListNode(1);
        head=head->next;
         temp=head;
         prev=NULL; 
        while(temp!=NULL){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
       head=prev;
       return head;
    }
};