#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = list1 != NULL ? list1 : list2;

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

void testMergeTwoLists()
{
    const int arr1[] = {1, 3, 5};
    const int arr2[] = {2, 4, 6};
    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* list2 = createList(arr2, 3);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    printList(mergedList); // Expected output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    freeList(mergedList);
}

int main()
{
    testMergeTwoLists();
    return 0;
}
