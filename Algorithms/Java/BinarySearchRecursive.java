class BinarySearchRecursive {
    int searchPosition(int[] arr, int target, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            return searchPosition(arr, target, start, mid - 1);
        } else {
            return searchPosition(arr, target, mid + 1, end);
        }
    }

    public static void main(String[] args) {
        BinarySearchRecursive bs = new BinarySearchRecursive();
        int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
        int target = 5;
        int position = bs.searchPosition(arr, target, 0, arr.length - 1);
        System.out.println(position);
    }
}
