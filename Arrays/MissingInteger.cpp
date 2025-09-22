#include<iostream>
using namespace std;

int missingInteger(int arr[], int N) {
    int xor1 = 0, xor2 = 0;
    int n = N-1;
    for(int i=0;i<n;i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ arr[i+1];
    }
    xor1 = xor1^N;
    return xor1 ^ xor2;

}


int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}


return 0;
}



