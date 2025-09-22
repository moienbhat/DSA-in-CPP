#include<iostream>
using namespace std;

int longestSubarraywithSumK(int arr[], int n, long long k) {
    int left, right = 0;
    long long sum = arr[0];
    int maxLength = 0;
    while(right<n) {
        while(left <= right && sum > k)
     {   sum -= arr[left];
        left++;}
    
    if(sum == k) {
        maxLength = max(maxLength, right - left + 1);
    }
    right ++;
    if(right<n) sum += arr[right];


    }
return maxLength;

}
int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;

    long long k;
cout<<"Enter sum of subArray: ";
cin>>k;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int length = longestSubarraywithSumK(arr, n, k);
cout<<"The length of longest subarray with sum k is: "<<length<<endl;

return 0;
}



