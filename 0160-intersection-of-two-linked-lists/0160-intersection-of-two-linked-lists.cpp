/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      /* O(max(m,n));
       unordered_map<ListNode*,int>mp;
        while(headA!=NULL){
            mp[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(mp.count(headB)){
                cout<<headB->val;
                return headB;
            }
            headB=headB->next;
        }
        return NULL;*/
        ListNode* t1=headA;
        ListNode* t2=headB;
        ListNode* temp1=headA;
        ListNode* temp2=headB;        
        while(t1!=NULL && t2!=NULL){
            t1=t1->next;
            t2=t2->next;
        }
        
        if(t1!=NULL){
            while(t1!=NULL){
                temp1=temp1->next;
                t1=t1->next;
            }

        }
        else if(t2!=NULL){
            while(t2!=NULL){
                temp2=temp2->next;
                t2=t2->next;
            }
        }
            while(temp1!=NULL && temp2!=NULL && temp1!=temp2){
                temp1=temp1->next;
                temp2=temp2->next;
            }
        
        return temp1;
    }
};