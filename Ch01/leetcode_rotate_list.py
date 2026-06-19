# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import copy
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if not head:
            return head
        if head.next == None:
            return head
        last = copy.copy(head)
        N = 1
        while last.next != None:
            last = last.next
            N += 1
        
        for _ in range(N-k%N):
            last.next = head
            last = last.next
            head = head.next
            last.next = None
        return head
            

        