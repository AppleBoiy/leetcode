from typing import Optional


class ListNode:
    def __init__(self, val=0, _next=None):
        self.val = val
        self.next = _next


class Solution:

    def addTwoNumbers(  # noqa
            self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode()
        current = dummy

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            carry, val = divmod(val1 + val2 + carry, 10)
            current.next = ListNode(val)
            current = current.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next


def main():
    solution = Solution()
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))
    result = solution.addTwoNumbers(l1, l2)
    while result:
        print(result.val, end=' -> ')
        result = result.next
    print('None')


if __name__ == '__main__':
    main()
