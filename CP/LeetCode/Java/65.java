// 65. Valid Number

class Solution {
    public boolean isNumber(final String s) {
        String newStr = new String(s);
        newStr = newStr.trim();
        if (newStr.length() == 0) {
            return false;
        }

        boolean isNumber = false;
        boolean isExponent = false;
        boolean isDecimal = false;

        for (int i = 0; i < newStr.length(); i++) {
            char ch = newStr.charAt(i);
            if (Character.isDigit(ch)) {
                isNumber = true;
            } else if (ch == '+' || ch == '-') {
                if (i > 0 && newStr.charAt(i - 1) != 'e') {
                    return false;
                }
            } else if (ch == 'e') {
                if (isExponent || !isNumber) {
                    return false;
                }
                isExponent = true;
                isNumber = false;
            } else if (ch == '.') {
                if (isDecimal || isExponent) {
                    return false;
                }
                isDecimal = true;
            } else {
                return false;
            }
        }

        return isNumber;
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isNumber("0")); // true
        System.out.println(solution.isNumber(" 0.1 ")); // true
        System.out.println(solution.isNumber("abc")); // false
        System.out.println(solution.isNumber("1 a")); // false
        System.out.println(solution.isNumber("2e10")); // true
        System.out.println(solution.isNumber(" -90e3   ")); // true
        System.out.println(solution.isNumber(" 1e")); // false
        System.out.println(solution.isNumber("e3")); // false
        System.out.println(solution.isNumber(" 6e-1")); // true
        System.out.println(solution.isNumber(" 99e2.5 ")); // false
        System.out.println(solution.isNumber("53.5e93")); // true
        System.out.println(solution.isNumber(" --6 ")); // false
        System.out.println(solution.isNumber("-+3")); // false
        System.out.println(solution.isNumber("95a54e53")); // false
    }
}
