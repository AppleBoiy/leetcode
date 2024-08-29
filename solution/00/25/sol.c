#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseKGroup(struct ListNode* head, const int k)
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    while (current->next != NULL)
    {
        struct ListNode* group_head = current->next;
        struct ListNode* group_tail = group_head;
        for (int i = 0; i < k - 1; i++)
        {
            group_tail = group_tail->next;
            if (group_tail == NULL)
            {
                return dummy.next;
            }
        }

        struct ListNode* next = group_tail->next;
        group_tail->next = NULL;

        struct ListNode* prev = NULL;
        struct ListNode* node = group_head;
        while (node != NULL)
        {
            struct ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }

        current->next = group_tail;
        group_head->next = next;
        current = group_head;
    }

    return dummy.next;
}

struct ListNode* createList(const int* arr, const int size)
{
    if (size == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;

    for (int i = 1; i < size; i++)
    {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }

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

void freeList(struct ListNode* head)
{
    while (head != NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void testReverseKGroup()
{
    const int arr[] = {1, 2, 3, 4, 5};
    struct ListNode* list = createList(arr, 5);

    struct ListNode* reversed = reverseKGroup(list, 2);

    const int expected[] = {2, 1, 4, 3, 5};
    const struct ListNode* temp = reversed;
    for (int i = 0; i < 5; i++)
    {
        assert(temp != NULL);
        assert(temp->val == expected[i]);
        temp = temp->next;
    }

    freeList(reversed);
}

int main()
{
    testReverseKGroup();
    printf("All tests passed!\n");
    return 0;
}
