// 4. Median of Two Sorted Arrays

class Solution {
    public double findMedianSortedArrays(final int[] nums1, final int[] nums2) {
        int n = nums1.length;

        int m = nums2.length;
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0;

        int r = n;
        while (l <= r) {
            int partX = (l + r) / 2;
            int partY = (n + m + 1) / 2 - partX;

            int maxLeftX = (partX == 0) ? Integer.MIN_VALUE : nums1[partX - 1];
            int minRightX = (partX == n) ? Integer.MAX_VALUE : nums1[partX];

            int maxLeftY = (partY == 0) ? Integer.MIN_VALUE : nums2[partY - 1];
            int minRightY = (partY == m) ? Integer.MAX_VALUE : nums2[partY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((n + m) % 2 == 0) {
                    return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2.0;
                } else {
                    return Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                r = partX - 1;
            } else {
                l = partX + 1;
            }
        }

        return 0.0;
    }

    public static void main(final String[] args) {
        int[] nums1 = { 1, 3 };
        int[] nums2 = { 2 };
        Solution s = new Solution();
        System.out.println(s.findMedianSortedArrays(nums1, nums2));
    }
}
