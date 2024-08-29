/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    for (int i = 0; i < left - 1; i++) {
        current = current->next;
    }

    struct ListNode* left_node = current->next;
    struct ListNode* right_node = left_node;
    for (int i = 0; i < right - left; i++) {
        right_node = right_node->next;
    }

    struct ListNode* next = right_node->next;
    right_node->next = NULL;

    struct ListNode* prev = NULL;
    struct ListNode* node = left_node;
    while (node != NULL) {
        struct ListNode* temp = node->next;
        node->next = prev;
        prev = node;
        node = temp;
    }

    current->next = right_node;
    left_node->next = next;

    return dummy.next;
}