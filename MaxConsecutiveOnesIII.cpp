#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int longestOnes(vector <int> &nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                zeroCount++;
            }

            if(zeroCount > k) {
                if(nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left  + 1);

        }
        return maxLen;

    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout<< "Max consecutive ones are: " << sol.longestOnes(nums, k) << endl;

    return 0;
}