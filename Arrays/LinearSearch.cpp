#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
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

    int key;
    cout<<"Enter element to find: ";
    cin>>key;

    int index = LinearSearch(arr, n, key);
    if(index != -1){
        cout<<"Element found at index "<<index<<endl;}
    else{
            cout<<"Element not found"<<endl;
        }

        
    return 0;
}



