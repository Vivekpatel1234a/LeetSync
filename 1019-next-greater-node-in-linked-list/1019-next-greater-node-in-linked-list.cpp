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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        int n=0;
        //reversal part
        while(temp!=NULL){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
            n++;
        }

       head=prev;
       //stack part 
       stack<int>st;
       vector<int>ans(n);
       int i=0;
       while(head!=NULL){
        int x=head->val;
        head=head->next;
        if(st.size()){
            while(st.size() && st.top()<=x){
                st.pop();
            }
        }
        if(st.size()==0)ans[n-1-i]=0;
        else ans[n-1-i]=st.top();
        st.push(x);
        i++;
       }
       return ans;
    }
};