class Solution:
    def isConsecutive(self, nums: List[int]) -> bool:
        nums_set = set(tuple(nums))
        min_val = min(nums)
        nums_size = len(nums)
        test_range = set(x for x in range(min_val, min_val + nums_size))
        return nums_set == test_range
