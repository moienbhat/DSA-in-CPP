#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        do {
            i++;
        } while (i < high && arr[i] <= pivot);

        do {
            j--;
        } while (j > low && arr[j] > pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]); 
    return j;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        QuickSort(arr, low, j);
        QuickSort(arr, j + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
