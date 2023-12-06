public class selection_sort {
    public static void sel_sort(int arr[]){
        for(int i = 0;i<arr.length;i++){
            int min = arr[i],index = i;
            for(int j = i;j<arr.length;j++){
                if(min>arr[j]){
                    index = j;
                    min = arr[j];
                }
            }
            int temp = arr[i];
            arr[i] = min;
            arr[index] = temp;
        }
    }
    public static void main(String[] args){
        int arr[] = {7,45,82,5,72,6,36,8};
        // merge(arr, 0, arr, arr.length-1);
        sel_sort(arr);
        for(int i = 0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
    }
}
