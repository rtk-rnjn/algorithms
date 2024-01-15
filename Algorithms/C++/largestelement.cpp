#include <iostream>
#include <climits>

using namespace std;

int main(){

    int arr[]= {-1,-11,5,6,7,9};
    int size = 6;
    
    int largest = INT_MIN;
    //use INT_MIN in array whose elements are not known 
    //or any negative element present in array 
    // INT_MIN present in climits library
    

   for (int i = 0;i<size;i++){
    if (arr[i]>largest){
        largest = arr[i];
    }
   }

   cout<<"The largest element in the arrray is :"<<largest<<endl;
   return 0;
}