class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:

        def removes(s, lc, rc):
            stk = 0
            res = ''
            for c in s:
                if c == lc:
                    stk += 1
                if c == rc:
                    stk -= 1
                if stk >= 0:
                    res += c
                else:
                    stk = 0
            return res
        
        s = removes(s, '(', ')')
        s = s[::-1]
        s = removes(s, ')', '(')
        s = s[::-1]
        return s