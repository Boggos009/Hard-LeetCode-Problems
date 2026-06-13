from typing import List
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)

        DPLEFT = [0] * n
        DPRIGHT = [0] * n

        for i in range(n - 1, -1, -1):
            maxi = 0

            for j in range(i + 1, n):
                if nums[i] > nums[j]:
                    maxi = max(maxi, DPLEFT[j])

            DPLEFT[i] = maxi + 1

        for i in range(n):
            maxi = 0

            for j in range(i - 1, -1, -1):
                if nums[i] > nums[j]:
                    maxi = max(maxi, DPRIGHT[j])

            DPRIGHT[i] = maxi + 1

        maxMountain = 0

        for i in range(n):
            if DPRIGHT[i] > 1 and DPLEFT[i] > 1:
                maxMountain = max(maxMountain, DPRIGHT[i] + DPLEFT[i] - 1)

        return n - maxMountain