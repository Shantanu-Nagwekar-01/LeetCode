class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {}
        for index, num in enumerate(nums):
            hashmap[num] = index
        for index, num in enumerate(nums):
            n = target - num
            if n in hashmap and hashmap[n] != index:
                return [index, hashmap[n]]

sol = Solution()
nums = [2,7,11,15]
target = 9
print(f"Output: {sol.twoSum(nums,target)}")