// 392. Is Subsequence

class Solution {

    public boolean isSubsequence(final String s, final String t) {
        int indexS = 0;
        int indexT = 0;

        while (indexS < s.length() && indexT < t.length()) {
            char charS = s.charAt(indexS);
            char charT = t.charAt(indexT);

            if (charS == charT) {
                indexS = indexS + 1;
            }
            indexT = indexT + 1;
        }

        return indexS == s.length();
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.isSubsequence("abc", "ahbgdc")); // true
        System.out.println(solution.isSubsequence("axc", "ahbgdc")); // false
    }
}
