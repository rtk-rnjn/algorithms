public class quick_sort {
    public static int partition(int arr[],int low ,int high){
        int pivot = arr[high];
        int i = low-1;
        for(int j = low;j<=high;j++){
            if(arr[j]<pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = pivot;
        arr[high] = temp;   
        return i+1;
    }
    public static void q_sort(int arr[],int low,int high){
        if(low<high){
            int pi = partition(arr, low, high);
            q_sort(arr, low, pi-1);
            q_sort(arr, pi+1, high);
        }
    }
    public static void main(String[] args){
        int arr[] = {7,45,82,5,72,6,36,8};
        q_sort(arr, 0, arr.length-1);
        for(int i = 0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
    }
}
