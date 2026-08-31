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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=-1;//it stores thee 1st minidx
        int minans=INT_MAX;//it stores the minans which satisfies conditon
        int prev=-1;//it stores the max idx which satisfies condition
        if(head->next->next==NULL)return {-1,-1};
        ListNode* temp=head;
        int idx=2;
        while(temp!=NULL){
            if(temp->next->next==NULL)break;
            int l=temp->val;
            int mid=temp->next->val;
            int r=temp->next->next->val;
            if((l<mid && mid>r) || (l>mid && r>mid)){
                if(mini==-1){
                    mini=idx;
                }
                else{
                    if(prev!=-1){
                       minans=min(minans,idx-prev);
                    }

                }
                prev=idx;
            }
            temp=temp->next;
            idx++;
        }
       // cout<<mini<<" "<<prev<<" "<<minans;
        if(mini!=-1 && prev!=-1 && minans!=INT_MAX){
           return {minans,prev-mini};
        }
        return {-1,-1};
    }
};