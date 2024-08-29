#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

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
    static ListNode* mergeKLists(const vector<ListNode*>& lists)
    {
        auto cmp = [](const ListNode* a, const ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* list : lists)
        {
            if (list)
            {
                minHeap.push(list);
            }
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty())
        {
            ListNode* minNode = minHeap.top();
            minHeap.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next)
            {
                minHeap.push(minNode->next);
            }
        }

        return dummy.next;
    }
};

ListNode* createList(const vector<int>& vals)
{
    ListNode dummy;
    ListNode* current = &dummy;

    for (const int val : vals)
    {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy.next;
}

vector<int> listToVector(const ListNode* head)
{
    vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
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

void testMergeKLists()
{
    const vector lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    const ListNode* merged = Solution::mergeKLists(lists);
    const vector<int> result = listToVector(merged);
    const vector expected = {1, 1, 2, 3, 4, 4, 5, 6};

    assert(result == expected);

    freeList(merged);
}

int main()
{
    testMergeKLists();
    cout << "All tests passed!\n";
    return 0;
}
