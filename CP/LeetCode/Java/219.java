// 219. Contains Duplicate II

import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean containsNearbyDuplicate(final int[] nums, final int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (map.containsKey(nums[i]) && i - map.get(nums[i]) <= k) {
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.containsNearbyDuplicate(new int[] { 1, 2, 3, 1 }, 3));
        System.out.println(solution.containsNearbyDuplicate(new int[] { 1, 0, 1, 1 }, 1));
        System.out.println(solution.containsNearbyDuplicate(new int[] { 1, 2, 3, 1, 2, 3 }, 2));
    }
}
