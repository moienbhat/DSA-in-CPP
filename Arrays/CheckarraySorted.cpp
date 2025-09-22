#include<iostream>
using namespace std;

int isSorted(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
        }
        else{
            return false;
        }
    }
    return true;
}


int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int sorted = isSorted(arr, n);
if(sorted==true){
    cout<<"Array is sorted"<<endl;
}
else{
    cout<<"Array is not sorted"<<endl;
}



return 0;
}



