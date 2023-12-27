public class SearchingRecursive {
    public static int binarySearch(int[] arr, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int middle = (right - left) / 2 + left;
        if (arr[middle] == target) {
            return middle;
        } else if (arr[middle] < target) {
            return binarySearch(arr, target, middle + 1, right);
        } else if (arr[middle] > target) {
            return binarySearch(arr, target, left, middle - 1);
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        System.out.println(binarySearch(arr, 3, 0, arr.length - 1));
    }
    
}
