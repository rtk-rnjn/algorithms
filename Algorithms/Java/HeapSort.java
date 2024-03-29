class HeapSort {
    public static void heapSort(final int[] arr, final int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }
    }

    public static void heapify(final int[] arr, final int size, final int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (largest != index) {
            int swap = arr[index];
            arr[index] = arr[largest];
            arr[largest] = swap;

            heapify(arr, size, largest);
        }
    }

    public static void main(final String[] args) {
        int[] arr = { 12, 11, 13, 5, 6, 7 };
        int size = arr.length;

        heapSort(arr, size);

        System.out.println("Sorted array is");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
