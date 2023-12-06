public class insertion_sort {
    public static void ins_sort(int arr[]){
        for(int i = 1;i<arr.length;i++){
            int j = i-1;
            int key = arr[i];
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }
    }
    public static void main(String[] args){
        int arr[] = {2,7,4,2,8,3,1};
        ins_sort(arr);
        for(int i = 0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
    }    
}
