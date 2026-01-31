#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int atMostK(vector <int>& nums, int k) {
    unordered_map<int, int> freq;
    int left = 0, count = 0;

    for(int right =0; right < nums.size(); right++) {
        if(freq[nums[right]] == 0) {
            k--;
        }
        freq[nums[right]]++;

        while(k < 0) {
            freq[nums[left]]--;
            if(freq[nums[left]] == 0) {
                k++;
            }
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}   


int main() {
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout<< "The number of subarrays with exactly K different integers is : "<< subarraysWithKDistinct(nums,k)<< endl;
    return 0;
}