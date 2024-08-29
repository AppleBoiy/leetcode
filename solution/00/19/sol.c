#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, const int n)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* slow = &dummy;
    const struct ListNode* fast = &dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy.next;
}

struct ListNode* createList(const int* arr, const int size)
{
    if (size == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    struct ListNode* current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
    }
    current->next = NULL;

    return head;
}

void printList(const struct ListNode* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(const struct ListNode* head)
{
    while (head != NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void testRemoveNthFromEnd()
{
    const int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createList(arr, 5);

    head = removeNthFromEnd(head, 2);
    const int expected[] = {1, 2, 3, 5};
    const struct ListNode* temp = head;
    for (int i = 0; i < 4; i++)
    {
        assert(temp != NULL);
        assert(temp->val == expected[i]);
        temp = temp->next;
    }
    assert(temp == NULL);

    freeList(head);
}

int main()
{
    testRemoveNthFromEnd();
    printf("All tests passed!\n");
    return 0;
}
