#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // function to count subarrays with at most k odd numbers
    int countAtMost(vector<int>& nums, int k) {
        // Initialize variables
        int left = 0, res = 0;

        // Traverse through the array
        for (int right = 0; right < nums.size(); right++) {
            // If current number is odd, reduce k
            if (nums[right] % 2 != 0)
                k--;

            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }

            // Add valid subarrays ending at right
            res += (right - left + 1);
        }

        // Return the count of valid subarrays
        return res;
    }

    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}

   