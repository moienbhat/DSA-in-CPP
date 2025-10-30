#include<iostream>
using namespace std;

// Function to set the rightmost unset bit (0 -> 1)
int setRightmostUnsetBit(int n) {
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}

int main() {
    // Sample input
    int n = 10; // binary: 1010

    // Call function
    int result = setRightmostUnsetBit(n);

    // Print output
    cout << "Number after setting rightmost unset bit: " << result << endl; // Output: 11

    return 0;
}
