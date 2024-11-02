class SumOfDigits {
    public static void main(final String[] args) {
        int n = 123;
        System.out.println(sumOfDigits(n));
    }

    public static int sumOfDigits(final int number) {
        int sum = 0;
        int n = number;

        while (n > 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
}
