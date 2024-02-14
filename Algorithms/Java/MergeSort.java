class MergeSort {
    public static void mergeSort(final int[] arr, final int p, final int q) {
        if (p >= q) {
            return;
        }
        int mid = (q + p) / 2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid + 1, q);
        merge(arr, p, mid, q);

    }

    public static void merge(final int[] arr, final int p, final int mid, final int q) {
        int l1 = mid - p + 1;
        int l2 = q - mid;
        int[] m1 = new int[l1];
        int[] m2 = new int[l2];
        for (int i = 0; i < l1; i++) {
            m1[i] = arr[p + i];
        }
        for (int i = 0; i < l2; i++) {
            m2[i] = arr[mid + 1 + i];
        }

        int n1 = 0;
        int k = p;
        int n2 = 0;
        while (n1 < m1.length && n2 < m2.length) {
            if (m1[n1] < m2[n2]) {
                arr[k] = m1[n1++];
            } else {
                arr[k] = m2[n2++];
            }
            k++;
        }
        while (n1 < m1.length) {
            arr[k++] = m1[n1++];
        }
        while (n2 < m2.length) {
            arr[k++] = m2[n2++];
        }

    }

    public static void main(final String[] args) {
        int[] arr = { 7, 45, 82, 5, 72, 6, 36, 8 };
        mergeSort(arr, 0, arr.length - 1);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
