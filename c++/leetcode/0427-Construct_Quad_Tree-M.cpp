class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        const int n = grid.size();

        function<Node*(int, int, int, int)> build;
        build = [&](int i0, int i1, int j0, int j1) {
            if (i0 == i1 && j0 == j1) {
                return new Node(grid[i0][j0], true);
            }
            int id = (i1 - i0) / 2;
            int jd = (j1 - j0) / 2; 
            Node* node1 = build(i0, i0 + id,     j0, j0 + jd);
            Node* node2 = build(i0, i0 + id,     j0 + jd + 1, j1);
            Node* node3 = build(i0 + id + 1, i1, j0, j0 + jd);
            Node* node4 = build(i0 + id + 1, i1, j0 + jd + 1, j1);
            if (node1->isLeaf && node2->isLeaf && node3->isLeaf && node4->isLeaf) {
                if (node1->val == node2->val && node1->val == node3->val && node1->val == node4->val) {
                    int val = node1->val;
                    delete node1;
                    delete node2;
                    delete node3;
                    delete node4;
                    return new Node(val, true);
                }
            }
            return new Node(true, false, node1, node2, node3, node4);
        };

        return build(0, n - 1, 0, n - 1);
    }
};
