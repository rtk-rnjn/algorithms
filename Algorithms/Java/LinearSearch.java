class LinearSearch {
    public static int search(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            // Return the index of the element if the element
            // is found
            if (arr[i] == target) {
                return i;
            }
        }

        // return -1 if the element is not found
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        int target = 3;

        int result = search(arr, target);
        System.out.println(result);
    }
}