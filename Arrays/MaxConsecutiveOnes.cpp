#include<iostream>
using namespace std;

int maxConsecutiveOnes(int arr[] , int n) {
    int maxi = 0;
    int cnt = 0;for(int i =0;i<n;i++) {
        if(arr[i] == 1){
            cnt++;
            maxi = max(maxi, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
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



