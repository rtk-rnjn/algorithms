// 26. Remove Duplicates from Sorted Array

class Solution {
    public int removeDuplicates(final int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        int[] nums = { 1, 1, 2 };
        System.out.println(sol.removeDuplicates(nums));
    }
}
