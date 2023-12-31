class TailRecursive {
    public static void main(String[] args) {
        System.out.println(factorial(5));
    }

    public static int factorial(int n) {
        return factorial(n, 1);
    }

    public static int factorial(int n, int result) {
        if (n == 0) {
            return result;
        } else {
            return factorial(n - 1, n * result);
        }
    }
}