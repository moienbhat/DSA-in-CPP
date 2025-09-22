#include<iostream>
using namespace std;



// Kadane's Algorithm

long long maxSubArraySum(int arr[], int n) {
    long long sum = 0, maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum > maxi) {
            maxi = sum;
        }

        if(sum < 0) {
            sum = 0;
        }
    }

    if(maxi < 0) return 0;
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



