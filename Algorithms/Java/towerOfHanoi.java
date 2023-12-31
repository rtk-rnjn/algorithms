class TowerOfHanoi {
    public static void toh3(int n, char A, char B, char C) {
        if (n == 1) {
            System.out.println(A + "->" + C);
            // return;
        } else if (n > 1) {
            toh3(n - 1, A, C, B);
            System.out.println(A + "->" + C);
            toh3(n - 1, B, A, C);
        }
    }

    public static void toh4(int n, char A, char B, char C, char D) {
        if (n == 0)
            return;
        if (n == 1) {
            System.out.println(A + "->" + D);
            return;
        } else {
            toh4(n - 2, A, C, D, B);
            System.out.println(A + "->" + C);
            System.out.println(A + "->" + D);
            System.out.println(C + "->" + D);
            toh4(n - 2, B, A, C, D);
        }
    }

    public static void main(String[] args) {
        toh4(3, 'A', 'B', 'C', 'D');

    }
}