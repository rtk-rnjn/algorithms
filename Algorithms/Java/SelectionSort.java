class SelectionSort {
    public static void selectionSort(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            int min = arr[i], index = i;
            for (int j = i; j < arr.length; j++) {
                if (min > arr[j]) {
                    index = j;
                    min = arr[j];
                }
            }
            int temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 7, 45, 82, 5, 72, 6, 36, 8 };
        selectionSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
