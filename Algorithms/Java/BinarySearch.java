class BinarySearch {
    int searchPosition(final int[] arr, final int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int middle = (right - left) / 2 + left;
            if (arr[middle] == target) {
                return middle;
            } else if (arr[middle] < target) {
                left = middle + 1;
            } else if (arr[middle] > target) {
                right = middle - 1;
            }
        }
        return -1;
    }

    public static void main(final String[] args) {
        BinarySearch bs = new BinarySearch();
        int[] arr = { 1, 2, 3, 4, 5 };
        System.out.println(bs.searchPosition(arr, 3));
    }
}