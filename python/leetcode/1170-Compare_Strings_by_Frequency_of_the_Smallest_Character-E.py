# 1170 Compare Strings by Frequency of the Smallest Character
# https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character

# version: 1; create time: 2019-10-20 14:44:35;
import bisect
from typing import List


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def smallestFreq(word: str) -> int:
            counter = [0 for i in range(26)]
            for c in word:
                counter[ord(c) - ord('a')] += 1
            for c in counter:
                if c:
                    return c

        word_freqs = sorted(map(smallestFreq, words))
        query_freqs = list(map(smallestFreq, queries))
        n = len(word_freqs)
        return [n - bisect.bisect_right(word_freqs, q) for q in query_freqs]

