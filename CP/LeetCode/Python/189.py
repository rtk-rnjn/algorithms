# 189. Rotate Array


class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        # k %= n
        # nums[:] = nums[-k:] + nums[:-k]

        k = k % n
        if k == 0:
            return
        
        from collections import deque
        dq = deque(nums)
        dq.rotate(k)
        nums[:] = list(dq)


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3

    solution.rotate(nums, k)
    print(nums)
