#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    vector<int> array = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    bubble_sort(array);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
