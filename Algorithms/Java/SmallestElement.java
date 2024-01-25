class SmallestElement {
    public static int smallestElement(int[] arr) {
        return smallestElement(arr, 0, arr.length - 1);
    }

    public static int smallestElement(int[] arr, int start, int end) {
        if (start == end) {
            return arr[start];
        } else {
            int mid = (start + end) / 2;
            int left = smallestElement(arr, start, mid);
            int right = smallestElement(arr, mid + 1, end);
            return Math.min(left, right);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        System.out.println(smallestElement(arr));
    }

}
