// String Reverse using String Builder

class StringReverse {
    public static String reverse(String str) {
        StringBuilder sb = new StringBuilder(str);
        for (int i = 0; i < sb.length() / 2; i++) {
            int front = i;
            int back = sb.length() - i - 1;

            char frontChar = sb.charAt(front);
            char backChar = sb.charAt(back);

            sb.setCharAt(front, backChar);
            sb.setCharAt(back, frontChar);
        }
        return sb.toString();
    }

    public static void main(String args[]) {
        String str = "Hello World";
        System.out.println(reverse(str));
    }
}
