#include<iostream>
using namespace std;

class solution {
    public:
    vector<int> singleNumber(vector<int> &nums) {
        int n = nums.size();

        long XOR = 0;
        for(int i=0; i<n; i++) {
            XOR = XOR^nums[i];
        }
        int rightMostBit = (XOR & (XOR - 1)) ^ XOR;;
        int XOR1 = 0, XOR2 = 0;

        for(int i=0;i<n; i++) {
            if(nums[i] & rightMostBit) {
                XOR1 = XOR1 ^ nums[i];
            }
            else{
                XOR2 = XOR2 ^ nums[i];
            }
        }
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};

int main() {
    vector<int> nums = {1,2,1,3,5,2};

    solution sol;
    vector<int> ans =  sol.singleNumber(nums);
    cout<< " the single numbers in given array are: "<<ans[0] <<" and " <<ans[1];

    return 0;
}