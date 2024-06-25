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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* start = head;
        ListNode* slow = head;
        ListNode* fast = head;

       while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp;
        ListNode* temp2;

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // Split the list into two halves
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* secondList = prev;

        while(secondList) {
            temp = start->next;
            temp2 = secondList->next;

            start->next = secondList;
            secondList->next = temp;

            secondList = temp2;
            start = temp;
        }

    }
};