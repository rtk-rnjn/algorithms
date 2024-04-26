class InsertionSort {
    public static void insertionSort(final int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int j = i - 1;
            int key = arr[i];
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(final String[] args) {
        int[] arr = { 2, 7, 4, 2, 8, 3, 1 };
        insertionSort(arr);

        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
