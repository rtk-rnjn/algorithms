class HeadRecursive {

    public static void print(int[] arr, int i) {
        if (i == arr.length) {
            return;
        }
        System.out.println(arr[i]);
        print(arr, i + 1);
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 6, 7, 8, 9 };
        print(arr, 0);
    }
}