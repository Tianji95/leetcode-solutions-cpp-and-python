# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        node1 = l1
        node2 = l2
        returnNode = ListNode(0)
        preNode = returnNode
        overSum = 0
        while node1 and node2:
            addSum  = node1.val + node2.val + overSum
            overSum = int(addSum / 10)
            thisSum = addSum % 10
            thisNode = ListNode(thisSum)
            preNode.next = thisNode
            preNode = preNode.next
            node1 = node1.next
            node2 = node2.next
        
        if node1:
            while node1:
                addSum = overSum + node1.val
                overSum = int(addSum / 10)
                thisSum = addSum % 10
                thisNode = ListNode(thisSum)
                preNode.next = thisNode
                preNode = preNode.next
                node1 = node1.next
                
        if node2:
            while node2:
                addSum = overSum + node2.val
                overSum = int(addSum / 10)
                thisSum = addSum % 10
                thisNode = ListNode(thisSum)
                preNode.next = thisNode
                preNode = preNode.next
                node2 = node2.next
                
        if overSum:
            thisNode = ListNode(overSum)
            preNode.next = thisNode
        return returnNode.next
                