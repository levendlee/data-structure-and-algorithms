# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return {}
        columns = collections.defaultdict(list)
        q = collections.deque()
        q.append((root, 0))
        while q:
            node, j = q.popleft()
            columns[j].append(node.val)
            if node.left:
                q.append((node.left, j - 1))
            if node.right:
                q.append((node.right, j + 1))
        return [c for _, c in sorted(columns.items())]