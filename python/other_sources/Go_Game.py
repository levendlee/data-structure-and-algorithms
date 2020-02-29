#!/usr/bin/env python3
# https://leetcode.com/discuss/interview-question/391195/
import typing
import unittest


class DFSError(Exception):
    pass


def go_name(board: typing.List[typing.List], x: int, y: int) -> int:
    m = len(board)
    if not m:
        return 0
    n = len(board[0])
    if not n:
        return 0

    def dfs(i: int, j: int, visit) -> typing.List:
        if board[i][j] == 'b':
            return []
        if board[i][j] == 'e':
            raise DFSError()
        if visit[i][j]:
            return []
        visit[i][j] = True
        stones = [(i, j)]
        for ni, nj in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
            if ni < 0 or ni >= m or nj < 0 or nj >= n:
                continue
            stones.extend(dfs(ni, nj, visit))
        return stones

    def play():
        visit = [[False for _ in range(n)] for _ in range(m)]
        stones = []
        for i in range(m):
            for j in range(n):
                try:
                    stones += dfs(i, j, visit)
                except DFSError:
                    continue
        for i, j in stones:
            board[i][j] = 'b'
        return len(stones)

    play()
    board[x][y] = 'b'
    return play()


e, b, w = 'e', 'b', 'w'


class Test(unittest.TestCase):
    def test_case0(self):
        board = [[e, e, e, e, b, b, b],
                 [e, e, e, e, b, w, b],
                 [e, e, e, e, b, e, b],
                 [e, e, e, e, e, e, e]]
        row, col = 2, 5
        self.assertEqual(go_name(board, row, col), 1)

    def test_case1(self):
        board = [[e, e, e, e, b, b, b],
                 [e, e, e, b, w, w, b],
                 [e, e, e, e, b, e, b],
                 [e, e, e, e, e, e, e]]
        row, col = 2, 5
        self.assertEqual(go_name(board, row, col), 2)

    def test_case2(self):
        board = [[e, e, b, b, b, b, b],
                 [e, e, b, w, e, w, b],
                 [e, e, b, b, b, e, b],
                 [e, e, e, e, e, e, e]]
        row, col = 2, 5
        self.assertEqual(go_name(board, row, col), 0)

    def test_case3(self):
        board = [[b, w, b, b, b, b, b],
                 [e, b, b, w, e, w, b],
                 [e, e, b, b, b, b, b],
                 [e, e, e, e, e, e, e]]
        row, col = 1, 4
        self.assertEqual(go_name(board, row, col), 2)


if __name__ == '__main__':
    unittest.main()
