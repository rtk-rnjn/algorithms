# 153. Find Minimum in Rotated Sorted Array

class Solution:
    def findMin(self, nums: list[int]) -> int:
        """
        Find the minimum element in a rotated sorted array.
        """
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        
        return nums[left]
    
if __name__ == "__main__":
    solution = Solution()
    nums = [3, 4, 5, 1, 2]
    
    print(solution.findMin(nums))  # Output: 1