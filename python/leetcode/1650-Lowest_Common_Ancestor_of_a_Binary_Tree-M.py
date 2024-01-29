"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        def get_ancestors(node):
            ancestors = []
            while node:
                ancestors.append(node)
                node = node.parent
            return ancestors
        pa = get_ancestors(p)
        pa_set = set(pa)
        qa = get_ancestors(q)
        qa_set = set(qa)
        for node in pa:
            if node in qa_set:
                return node
        for node in qa:
            if node in pq_set:
                return node
        return None