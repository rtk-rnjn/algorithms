# 27. Remove Element


class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        # while val in nums:
        #     nums.remove(val)

        # return len(nums)

        if not nums:
            return 0

        write_index = 0

        for read_index in range(len(nums)):
            if nums[read_index] != val:
                nums[write_index] = nums[read_index]
                write_index += 1

        return write_index


if __name__ == "__main__":
    nums = [3, 2, 2, 3]
    val = 3

    solution = Solution()
    new_length = solution.removeElement(nums, val)

    print(f"New length: {new_length}")
    print(f"Modified array: {nums[:new_length]}")
