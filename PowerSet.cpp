#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of
// the input array using bitwise operators
vector<vector<int>> getPowerSet(vector<int>& nums) {
    // Get the size of the input array
    int n = nums.size();
    // Calculate the total number of
    // subsets using bitwise left
    // shift operator
    int subsets = 1 << n;
    // Initialize a vector
    // to store all subsets
    vector<vector<int>> ans;
    
    // Iterate through all numbers
    // from 0 to subsets - 1
    for (int num = 0; num < subsets; num++) {
        // Initialize a vector to
        // store the current subset
        vector<int> subset;
        
        // Iterate through each bit
        // position in the current number
        for (int i = 0; i < n; i++) {
            // Check if the ith bit of
            // the current number is set
            if (num & (1 << i)) {
                // If the bit is set, add the
                // corresponding element from
                // the input array to the subset
                subset.push_back(nums[i]);
            }
        }
        
        // Add the current subset
        // to the list of subsets
        ans.push_back(subset);
    }
    
    // Return the vector
    // of all subsets
    return ans;
}

int main() {
    vector<int> nums = {5, 7, 8};
    vector<vector<int>> subsets = getPowerSet(nums);
    cout << "Initial Input Array: ";
    for (auto num: nums){
        cout << num << " ";
    }
    cout << endl;
    cout << "Subsets: " << endl;
    for (auto subset : subsets) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}