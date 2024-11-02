class CountingSort {
    public static void main(final String[] args) {
        int[] arr = { 4, 2, 2, 8, 3, 3, 1 };
        int[] sortedArr = countingSort(arr);

        for (int i : sortedArr) {
            System.out.print(i + " ");
        }
    }

    public static int[] countingSort(final int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        int[] count = new int[max + 1];
        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }

        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        int[] sortedArr = new int[arr.length];
        for (int i = arr.length - 1; i >= 0; i--) {
            sortedArr[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        return sortedArr;
    }
}
