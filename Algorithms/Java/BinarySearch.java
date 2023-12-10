class BinarySearch {
    int searchPosition(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
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

    public static void main(String[] args) {
        BinarySearch bs = new BinarySearch();
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println(bs.searchPosition(arr, 3));
    }
}