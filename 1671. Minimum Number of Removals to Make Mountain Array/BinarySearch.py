from typing import List
from bisect import bisect_left

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)

        DPLEFT = [0] * n
        DPRIGHT = [0] * n

        temp = []

        for i in range(n):
            pos = bisect_left(temp, nums[i])

            if pos == len(temp):
                temp.append(nums[i])
            else:
                temp[pos] = nums[i]

            DPRIGHT[i] = pos + 1

        temp = []

        for i in range(n - 1, -1, -1):
            pos = bisect_left(temp, nums[i])

            if pos == len(temp):
                temp.append(nums[i])
            else:
                temp[pos] = nums[i]

            DPLEFT[i] = pos + 1

        maxMountain = 0

        for i in range(n):
            if DPRIGHT[i] > 1 and DPLEFT[i] > 1:
                maxMountain = max(maxMountain, DPRIGHT[i] + DPLEFT[i] - 1)

        return n - maxMountain