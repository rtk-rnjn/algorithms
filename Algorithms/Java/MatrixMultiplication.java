import java.util.Scanner;

public class MatrixMultiplication {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of rows in matrix A: ");
        int rowsA = sc.nextInt();
        System.out.print("Enter the number of columns in matrix A: ");
        int columnsA = sc.nextInt();

        System.out.print("Enter the number of rows in matrix B: ");
        int rowsB = sc.nextInt();
        System.out.print("Enter the number of columns in matrix B: ");
        int columnsB = sc.nextInt();

        if (columnsA != rowsB) {
            System.out.println("Matrices cannot be multiplied.");
        } else {
            int[][] A = new int[rowsA][columnsA];
            int[][] B = new int[rowsB][columnsB];
            int[][] C = new int[rowsA][columnsB];

            System.out.println("Enter elements of matrix A: ");
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < columnsA; j++) {
                    A[i][j] = sc.nextInt();
                }
            }

            System.out.println("Enter elements of matrix B: ");
            for (int i = 0; i < rowsB; i++) {
                for (int j = 0; j < columnsB; j++) {
                    B[i][j] = sc.nextInt();
                }
            }

            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < columnsB; j++) {
                    for (int k = 0; k < columnsA; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            System.out.println("Resultant matrix C: ");
            for (int i = 0; i < rowsA; i++) {
                for (int j = 0; j < columnsB; j++) {
                    System.out.print(C[i][j] + " ");
                }
                System.out.println();

            }
        }

        sc.close();
    }
}
