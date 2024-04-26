package searching;
class LinearSearch {
    public static int linearSearch(final int[] arr, final int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }

        return -1;
    }

    public static void main(final String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        int target = 3;

        int result = linearSearch(arr, target);
        System.out.println(result);
    }
}
