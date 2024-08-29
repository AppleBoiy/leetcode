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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        int n = 1;
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
            n++;
        }

        current->next = head;

        k %= n;
        for (int i = 0; i < n - k; i++) {
            current = current->next;
        }

        head = current->next;
        current->next = nullptr;

        return head;
    }
};