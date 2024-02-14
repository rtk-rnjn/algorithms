// 38. Count and Say

class Solution {
    public String countAndSay(final int n) {
        if (n == 1) {
            return "1";
        }
        String prev = countAndSay(n - 1);
        StringBuilder sb = new StringBuilder();
        int count = 1;
        for (int i = 1; i < prev.length(); i++) {
            if (prev.charAt(i) == prev.charAt(i - 1)) {
                count++;
            } else {
                sb.append(count);
                sb.append(prev.charAt(i - 1));
                count = 1;
            }
        }
        sb.append(count);
        sb.append(prev.charAt(prev.length() - 1));
        return sb.toString();
    }

    public static void main(final String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countAndSay(4));
    }
}
