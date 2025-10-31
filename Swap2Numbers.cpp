#include<iostream>
using namespace std;

// Function to swap using XOR bit manipulation
void swapXOR(int &a, int &b) {
    // Step 1: XOR a and b, store in a
    a = a ^ b;

    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;

    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
}

int main() {
    int a = 5, b = 10;

    // Call the swap function
    swapXOR(a, b);

    // Print the result after swapping
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}