#include<iostream>
using namespace std;

class Solution {
public:
    /* Function to get the single 
    number in the given array */
    int singleNumber(vector<int>& nums){
        /* Variable to store XOR
        of all numbers in array */
        int XOR = 0;
        
        /* Iterate on the array to
        find XOR of all elements */
        for(int i = 0; i < nums.size(); i++) {
            XOR ^= nums[i];    
        }
        
        // XOR stores the required answer
        return XOR;        
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 4, 3, 1, 4};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the single 
    number in the given array */
    int ans = sol.singleNumber(nums);
    
    cout << "The single number in given array is: " << ans;
    
    return 0;
}