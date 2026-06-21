class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums_sorted = sorted(nums)
        N = len(nums_sorted)
        ans = [0 for _ in range(N)]

        mid = (N-1)/2
        end = N-1

        # first do the odd indices
        for i in range(1, N, 2):
            if i < N:
                nums[i] = nums_sorted[end]
                end -= 1

        # now the even indices
        for i in range(0, N, 2):
            if i < N:
                nums[i] = nums_sorted[mid]
                mid -= 1
    