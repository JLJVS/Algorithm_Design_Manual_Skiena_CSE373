class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        ans = [0 for _ in temperatures]
        stk = []
        N = len(temperatures)

        for i in range(N-1, -1, -1):
            temp = temperatures[i]
            while stk:
                if temperatures[stk[-1]] <= temp:
                    stk.pop()
                else:
                    ans[i] = stk[-1] - i
                    break
            stk.append(i)

        return ans