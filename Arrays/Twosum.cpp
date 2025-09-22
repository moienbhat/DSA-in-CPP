#include<iostream>
using namespace std;

string twoSum(int arr[], int n, int target) {
    int left = 0;
    int right = n-1;
    sort(arr, arr+n);

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            return "Yes";
        }
        else if(sum < target) left++;
        else right --;
    }
    return "No";
}


int main(){
    int n;
cout<<"Enter number of elements in array:";
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int target;
cout<<"Enter target sum:";
cin>>target;
cout<<twoSum(arr, n, target)<<endl;
return 0;


}



