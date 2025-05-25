# 169. Majority Element


class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        # nums.sort()
        # return nums[(len(nums) - 1)//2]

        # Boyer-Moore Voting Algorithm
        count = 0
        candidate = 0

        for num in nums:
            if count == 0:
                candidate = num

            if num == candidate:
                count += 1
            else:
                count -= 1

        return candidate


if __name__ == "__main__":
    solution = Solution()
    print(solution.majorityElement([3, 2, 3]))  # Output: 3
