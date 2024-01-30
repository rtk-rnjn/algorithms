class TailRecursive {

    public static int factorial(final int n) {
        return factorial(n, 1);
    }

    public static int factorial(final int n, final int result) {
        if (n == 0) {
            return result;
        } else {
            return factorial(n - 1, n * result);
        }
    }

    public static void main(final String[] args) {
        System.out.println(factorial(5));
    }
}
