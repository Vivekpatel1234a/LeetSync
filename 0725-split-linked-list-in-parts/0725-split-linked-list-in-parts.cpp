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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }

        int first=n%k;
        int second=min(k,n)-first;
        vector<ListNode*>arr(k);
        int ptr=0;
        temp=head;
        while(first--){
            int i=0;
            ListNode* newlist=temp;
            ListNode* newtemp=temp;
            int parts=n/k;
            while(i<parts+1){
                newtemp=temp;
                temp=temp->next;
                i++;
            }
            newtemp->next=NULL;
            arr[ptr++]=newlist;
        }
        cout<<second;
        while(second--){
            //cout<<ptr<<" ";
            int i=0;
            ListNode* newlist=temp;
            ListNode* newtemp=temp;
            int parts=n/k;
            while(i<parts){
                newtemp=temp;
                temp=temp->next;
                i++;
            }
            newtemp->next=NULL;
            arr[ptr++]=newlist;
        }


        
        return arr;
    }
};