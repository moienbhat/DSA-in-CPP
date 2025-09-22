#include <iostream>
using namespace std;

// void moveZeroesToEnd(int arr[], int n) {
//     vector<int> temp;
//     for(int i =0;i<n;i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }

//     int nz = temp.size();// number of non-zero elements
//     for(int i=0;i<nz;i++){
//         arr[i] = temp[i];
//     }
    
//     for(int i=nz;i<n;i++){
//         arr[i] = 0;
//     }
// }

void moveZeroesOptimal(int arr[], int n){
    int j = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j=i;
            break;
        }
    }

    for(int i =j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }

    }
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
    moveZeroesOptimal(arr, n);
    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;   

    

    return 0;
}
