class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ans = 0
        min_pos = -1
        max_pos = -1
        last_invalid_index = -1

        for i, num in enumerate(nums):
            if num < minK or num > maxK:
                last_invalid_index = i
            if num == minK:
                min_pos = i
            if num == maxK:
                max_pos = i

            valid_start = min(min_pos, max_pos)
            count = valid_start - last_invalid_index
            ans += count if count > 0 else 0

        return ans
