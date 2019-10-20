from typing import List


class Solution:
    def findSecretWord(self, word_list: List[str], master: 'Master') -> None:
        def calcMatch(word0: str, word1: str) -> int:
            return sum(char0 == char1 for char0, char1 in zip(word0, word1))

        for test in range(10):
            n = len(word_list)
            match_matrix = [[0 for j in range(n)] for i in range(n)]
            for i in range(n):
                for j in range(i, n):
                    match = calcMatch(word_list[i], word_list[j])
                    match_matrix[i][j] = match_matrix[j][i] = match

            guess_idx = max((sorted(match_matrix[i], reverse=True), i) for i in range(n))[1]
            guess_word = word_list[guess_idx]

            match = master.guess(guess_word)
            if match == 6:
                return

            word_list = [word_list[j] for j, m in enumerate(match_matrix[guess_idx]) if m == match]
