#include<iostream>
using namespace std;

class Solution {
public:
    // Function to check if a number is odd
    bool isOdd(int n) {
        return (n % 2 != 0);  // Return true if the number is odd, else false
    }
};

int main() {
    Solution sol;
    int num = 7;

    if (sol.isOdd(num)) {
        cout << num << " is odd." << endl;
    } else {
        cout << num << " is not odd." << endl;
    }

    return 0;
}