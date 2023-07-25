class Solution(object):
    def maxPalindromes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        is_palindrome = [[False] * n for _ in range(n)]
        for d in range(n):
            for i in range(n - d):
                j = i + d
                is_palindrome[i][j] = (s[i] == s[j]) and (j - i <= 1 or is_palindrome[i + 1][j - 1])

        max_num_palindromes = [0] * (n + 1)
        for j in range(k - 1, n):
            found = False
            for i in range(j - k + 1, -1, -1):
                if is_palindrome[i][j]:
                    found = True
                max_num_palindromes[j + 1] = max(max_num_palindromes[j + 1],
                                                 max_num_palindromes[i] + found)
        return max(max_num_palindromes)
