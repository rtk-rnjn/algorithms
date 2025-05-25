// 10. Regular Expression Matching

class Solution {

    public boolean isMatch(final String text, final String pattern) {
        final int textLength = text.length();
        final int patternLength = pattern.length();

        boolean[][] dp = new boolean[textLength + 1][patternLength + 1];
        dp[0][0] = true;

        for (int j = 2; j <= patternLength; j++) {
            if (pattern.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= textLength; i++) {
            for (int j = 1; j <= patternLength; j++) {
                char currentPatternChar = pattern.charAt(j - 1);

                if (currentPatternChar == '.' || currentPatternChar == text.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (currentPatternChar == '*') {
                    char precedingChar = pattern.charAt(j - 2);
                    dp[i][j] = dp[i][j - 2] || ((precedingChar == '.' || precedingChar == text.charAt(i - 1)) && dp[i - 1][j]);
                }
            }
        }

        return dp[textLength][patternLength];
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isMatch("aa", "a"));   // false
        System.out.println(solution.isMatch("aa", "a*"));  // true
        System.out.println(solution.isMatch("ab", ".*"));  // true
    }
}
