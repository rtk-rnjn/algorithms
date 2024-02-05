// 1. Two Sum

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(final int[] nums, final int target) {
        int[] result = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                result[0] = map.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            map.put(nums[i], i);
        }
        return result;
    }

    public static void main(final String[] args) {
        final Solution solution = new Solution();
        final int[] nums = { 2, 7, 11, 15 };
        final int target = 9;
        final int[] result = solution.twoSum(nums, target);
        System.out.println(result[0] + " " + result[1]);
    }
}
