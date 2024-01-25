class HeapSort {
    public static void heapSort(int[] arr, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }
    }

    public static void heapify(int arr[], int size, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // If right child is larger than largest so far
        if (right < size && arr[right] > arr[largest])
            largest = right;

        // If left child is larger than root
        if (left < size && arr[left] > arr[largest])
            largest = left;

        // If largest is not root
        if (largest != index) {
            int swap = arr[index];
            arr[index] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected sub-tree
            heapify(arr, size, largest);
        }
    }

    public static void main(String args[]) {
        int[] arr = { 12, 11, 13, 5, 6, 7 };
        int size = arr.length;

        heapSort(arr, size);

        System.out.println("Sorted array is");
        for (int i : arr)
            System.out.print(i + " ");
    }
}