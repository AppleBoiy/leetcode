#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(const struct ListNode* l1, const struct ListNode* l2)
{
    int carry = 0;
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        const int val1 = l1 != NULL ? l1->val : 0;
        const int val2 = l2 != NULL ? l2->val : 0;

        const int sum = val1 + val2 + carry;
        carry = sum / 10;
        const int val = sum % 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = val;
        current->next = NULL;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}

void printList(const struct ListNode* head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void deleteList(struct ListNode* head)
{
    while (head != NULL)
    {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

int main()
{
    // Create first list: [2, 4, 3]
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    // Create second list: [5, 6, 4]
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    // Add the two numbers
    struct ListNode* result = addTwoNumbers(l1, l2);

    // Print the result list
    printList(result);

    // Free the allocated memory
    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}
