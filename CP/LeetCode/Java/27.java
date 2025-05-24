// 27. Remove Element

class Solution {
    public int removeElement(final int[] nums, final int valToRemove) {
        int insertPos = 0;
        for (int current : nums) {
            if (current != valToRemove) {
                nums[insertPos++] = current;
            }
        }
        return insertPos;
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        int[] nums = { 3, 2, 2, 3 };
        int valToRemove = 3;

        System.out.println(sol.removeElement(nums, valToRemove));
    }
}
