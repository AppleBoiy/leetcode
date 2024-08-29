#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     explicit ListNode(const int x) : val(x), next(nullptr) {}
     ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode* current = &dummy;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            const int val1 = l1 != nullptr ? l1->val : 0;
            const int val2 = l2 != nullptr ? l2->val : 0;

            const int sum = val1 + val2 + carry;
            carry = sum / 10;
            const int val = sum % 10;

            current->next = new ListNode(val);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummy.next;
    }
};

void printList(const ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(const ListNode* head) {
    while (head != nullptr) {
        const ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // [2,4,3]
    const auto l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    // [5,6,4]
    const auto l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // [7,0,8]
    const auto result = Solution::addTwoNumbers(l1, l2);
    printList(result);

    // Clean up
    deleteList(l1);
    deleteList(l2);
    deleteList(result);
    return 0;
}