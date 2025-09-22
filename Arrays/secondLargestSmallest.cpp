#include<iostream>
using namespace std;

int secondLargest(int arr[] , int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i = 0; i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest= arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}



int secondSmallest(int arr[] , int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i = 0; i<n;i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}


int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int secLargest = secondLargest(arr, n);
cout<<secLargest<<endl;

int secSmallest = secondSmallest(arr, n);
cout<<secSmallest<<endl;



return 0;
}



