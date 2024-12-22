from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        new_head = head.next
        prev = None
        while head and head.next:
            first = head
            second = head.next
            head = second.next

            if prev:
                prev.next = second
            first.next = second.next
            second.next = first
            prev = first
        return new_head

def is_equal(left, other):
    while left and other:
        if left.val != other.val:
            return False
        left = left.next
        other = other.next
    return left is None and other is None

def test():
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    other = ListNode(2, ListNode(1, ListNode(4, ListNode(3))))
    assert is_equal(Solution().swapPairs(head), other)

    head = ListNode(1, ListNode(2, ListNode(3)))
    other = ListNode(2, ListNode(1, ListNode(3)))
    assert is_equal(Solution().swapPairs(head), other)

    head = ListNode(1, ListNode(2))
    other = ListNode(2, ListNode(1))
    assert is_equal(Solution().swapPairs(head), other)

    head = ListNode(1)
    other = ListNode(1)
    assert is_equal(Solution().swapPairs(head), other)

    head = None
    other = None
    assert is_equal(Solution().swapPairs(head), other)

    print('PASSED')

if __name__ == '__main__':
    test()
