public class SumOfDigitsRecursive {
    public static void main(final String[] args) {
        int n = 123;
        System.out.println(sumOfDigits(n));
    }

    public static int sumOfDigits(final int number) {
        if (number == 0) {
            return 0;
        }
        return number % 10 + sumOfDigits(number / 10);
    }
}
