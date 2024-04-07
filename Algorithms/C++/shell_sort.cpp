#include <iostream>
using namespace std;

int shellSort(int arr[], int size)
{
	for (int gap = size/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i += 1)
		{
			int temp = arr[i];

			int j;		 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			arr[j] = temp;
		}
	}
	return 0;
}


int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int size = sizeof(arr)/sizeof(arr[0]);

	shellSort(arr, size);
    for (int i=0; i<size; i++)
		cout << arr[i] << " ";

	return 0;
}
