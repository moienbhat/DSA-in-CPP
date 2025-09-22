
#include<iostream>
using namespace std;


int getSingleElement(int arr[], int n) {
    int xorr = 0;
    for(int i = 0; i< n;i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int ans = getSingleElement(arr, n);
cout<<"The element which appears once is: "<<ans<<endl;



return 0;
}



