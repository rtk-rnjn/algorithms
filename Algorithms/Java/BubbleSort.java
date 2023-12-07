public class BubbleSort {
    public static void bub_sort(int arr[]){
        for(int i = 0;i<arr.length;i++){
            for(int j = 0;j<arr.length - i - 1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    public static void main(String[] args){
        int arr[] = {7,45,82,5,72,6,36,8};
        bub_sort(arr);
        for(int i = 0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
    }
}
