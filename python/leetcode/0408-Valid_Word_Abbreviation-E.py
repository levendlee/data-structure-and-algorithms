class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        m = len(word)
        n = len(abbr)

        i = 0
        j = 0
        while i < m and j < n:
            if abbr[j].isalpha():
                if word[i] != abbr[j]:
                    return False
                i += 1
                j += 1
            else:
                if abbr[j] == '0':
                    return False
                start, end = j, j + 1
                while end < n and abbr[end].isdigit():
                    end += 1
                i += int(abbr[start:end])
                j = end
        
        return i == m and j == n