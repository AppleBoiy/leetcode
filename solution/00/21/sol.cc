#include <iostream>
#include <cassert>


struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {
    }

    explicit ListNode(const int x) : val(x), next(nullptr)
    {
    }

    ListNode(const int x, ListNode* next) : val(x), next(next)
    {
    }
};


class Solution
{
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy;
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr)
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

        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};

auto createList(const int* arr, const int size) -> ListNode*
{
    if (size == 0) return nullptr;

    const auto head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void freeList(const ListNode* head)
{
    while (head != nullptr)
    {
        const ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void testMergeTwoLists()
{
    Solution solution;

    constexpr int arr1[] = {1, 3, 5};
    constexpr int arr2[] = {2, 4, 6};
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    const ListNode* merged = solution.mergeTwoLists(list1, list2);
    const int expected[] = {1, 2, 3, 4, 5, 6};
    const ListNode* temp = merged;

    for (int i = 0; i < 6; i++)
    {
        assert(temp != nullptr);
        printf("%d -> ", temp->val);
        assert(temp->val == expected[i]);
        temp = temp->next;
    }
    assert(temp == nullptr);

    freeList(merged);
}

int main()
{
    testMergeTwoLists();
    std::cout << "All tests passed!\n";
    return 0;
}
