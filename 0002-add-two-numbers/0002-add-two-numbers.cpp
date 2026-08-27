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
        //clean code
        ListNode* temp=new ListNode(0);
        int c=0;
        ListNode* curr=temp;
        while(l1!=NULL || l2!=NULL){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=c;
            ListNode* sl=new ListNode(sum%10);
            curr->next=sl;
            curr=sl;
            c=sum/10;
        }
        if(c==1){
            curr->next=new ListNode(c);
        }
        return temp->next;
    }
};