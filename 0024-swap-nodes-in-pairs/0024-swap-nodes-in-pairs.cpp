class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            ListNode* nxt = temp->next->next;

            // swap
            prev->next = temp->next;
            temp->next->next = temp;
            temp->next = nxt;

            // move to next pair
            prev = temp;
            temp = nxt;
        }

        return dummy->next;
    }
};