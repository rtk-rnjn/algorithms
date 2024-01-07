#include <iostream>

using namespace std;

int main()
{
  int arr[] = {2, 13, 14, 3, 5};

  int size = 5;

  int sum = 0;

  for (int i = 0; i < size; i++)
  {
    sum = sum + arr[i];
  }
  cout << "Sum of all element is: " << sum << endl;
  return 0;
}