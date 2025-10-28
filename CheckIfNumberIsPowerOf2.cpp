#include<iostream>
using namespace std;

class Solution {
public:
    // Function to check if a number is a power of two
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;  // Check if n is greater than 0 and has only one bit set
    }
};

int main() {
    Solution sol;
    int num = 8;

    if (sol.isPowerOfTwo(num)) {
        cout << num << " is a power of two." << endl;
    } else {
        cout << num << " is not a power of two." << endl;
    }

    return 0;
}