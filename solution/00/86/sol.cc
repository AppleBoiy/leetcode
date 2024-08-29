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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1;
        ListNode dummy2;
        ListNode* current1 = &dummy1;
        ListNode* current2 = &dummy2;

        while (head != nullptr) {
            if (head->val < x) {
                current1->next = head;
                current1 = current1->next;
            } else {
                current2->next = head;
                current2 = current2->next;
            }
            head = head->next;
        }

        current1->next = dummy2.next;
        current2->next = nullptr;

        return dummy1.next;
    }
};