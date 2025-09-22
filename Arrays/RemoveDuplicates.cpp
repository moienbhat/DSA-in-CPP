#include<iostream>
using namespace std;

int RemoveDuplicates(int arr[], int n){
    int i = 0;
    for(int j=0;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int size = RemoveDuplicates(arr, n);
cout<<size<<endl;


return 0;
}



