#include <iostream>
using namespace std;

void rotate(int arr[], int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n]; // works in GCC/Clang, but use vector<int> in standard C++
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    rotate(arr, n);

    cout << "Array after one rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
