class TowerOfHanoi {
    public static void toh3(final int n, final char rodA, final char rodB, final char rodC) {
        if (n == 1) {
            System.out.println(rodA + "->" + rodC);
            // return;
        } else if (n > 1) {
            toh3(n - 1, rodA, rodC, rodB);
            System.out.println(rodA + "->" + rodC);
            toh3(n - 1, rodB, rodA, rodC);
        }
    }

    public static void toh4(final int n, final char rodA, final char rodB, final char rodC, final char rodD) {
        if (n == 0) {
            return;
        }
        if (n == 1) {
            System.out.println(rodA + "->" + rodD);
            return;
        } else {
            toh4(n - 2, rodA, rodC, rodD, rodB);
            System.out.println(rodA + "->" + rodC);
            System.out.println(rodA + "->" + rodD);
            System.out.println(rodC + "->" + rodD);
            toh4(n - 2, rodB, rodA, rodC, rodD);
        }
    }

    public static void main(final String[] args) {
        toh4(3, 'A', 'B', 'C', 'D');
    }
}
