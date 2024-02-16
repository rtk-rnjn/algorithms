class BubbleSort {
    public static void bubbleSort(final int[] arr) {
        boolean sorted;
        for (int i = 0; i < arr.length; i++) {
            sorted = false;
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    sorted = false;
                    
                }
                else{
                    sorted = true;
                }
            }
            if(sorted){
                break;
            }
        }
    }

    public static void main(final String[] args) {
        int[] arr = { 7, 45, 82, 5, 72, 6, 36, 8, 100, 99, 98, 97,0};
        bubbleSort(arr);

        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
