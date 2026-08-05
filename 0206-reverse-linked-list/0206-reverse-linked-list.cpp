class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
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




//not better
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL)return head;
//          ListNode* prev=NULL;
//         ListNode* temp1=head;
//         ListNode* temp2=temp1->next;
//         while(temp2!=NULL){
//             temp1->next=prev;
//             prev=temp1;
//             temp1=temp2;
//             temp2=temp2->next;
//         }
//         if(temp1!=NULL){
//         temp1->next=prev;
//         prev=temp1;
//         }
//         return prev;
//     }
// };