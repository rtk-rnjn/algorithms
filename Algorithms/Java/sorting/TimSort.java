package sorting;
class TimSort {
    // CSOFF: StaticVariableName
    // CSOFF: VisibilityModifier
    public static int RUN = 32;
    // CSON: StaticVariableName
    // CSON: VisibilityModifier

    public static void insertionSort(final int[] arr, final int left, final int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }

    public static void merge(final int[] arr, final int l, final int m, final int r) {
        int len1 = m - l + 1;
        int len2 = r - m;
        int[] left = new int[len1];
        int[] right = new int[len2];
        for (int x = 0; x < len1; x++) {
            left[x] = arr[l + x];
        }
        for (int x = 0; x < len2; x++) {
            right[x] = arr[m + 1 + x];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < len1) {
            arr[k] = left[i];
            k++;
            i++;
        }

        while (j < len2) {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    public static void timSort(final int[] arr, final int n) {
        for (int i = 0; i < n; i += RUN) {
            insertionSort(arr, i, Math.min((i + 31), (n - 1)));
        }

        for (int size = RUN; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min((left + 2 * size - 1), (n - 1));
                merge(arr, left, mid, right);
            }
        }
    }

    public static void main(final String[] args) {
        int[] arr = {5, 21, 7, 23, 19};
        System.out.println("Array before sorting:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
        timSort(arr, arr.length);

        System.out.println("Array after sorting:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
