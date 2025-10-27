#include<iostream>
using namespace std;

class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        // Check if the i-th bit is set using bitwise AND operation
        return (n & (1 << i)) != 0;  // If the i-th bit is 1, the result will be non-zero
    }
};

int main() {
    Solution sol;
    int num = 5;  // Binary: 101
    int bitIndex = 2;  // Check the 2nd bit (0-based index)

    if (sol.checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}
