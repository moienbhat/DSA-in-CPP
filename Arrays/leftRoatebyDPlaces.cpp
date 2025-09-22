
#include <iostream>
using namespace std;


void reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int n, int d){
//     d = d % n;

//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i] = arr[i];
//     }

//     for(int i =d; i<n; i++){
//         arr[i-d] = arr[i];
//     }

//     for(int i =n-d;i<n;i++){
//         arr[i] =temp[i-(n-d)];
//     }
       reverse(arr,arr+d);
       reverse(arr+d,arr+n);
       reverse(arr,arr+n);
 }

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n]; 
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int d;
    cout<<"Enter number of places to rotate the array by: ";
    cin>>d;


    leftRotate(arr, n,d);

    cout << "Array after one rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
