#include<iostream>
using namespace std;

class Solution {
private:
    /* Function to find the XOR 
    of numbers from 1 to n*/
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    
public:
    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
		return XORtillN(l-1) ^ XORtillN(r);
	}
};

int main() {
    int l = 3, r = 5;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the
    XOR of numbers from L to R*/
    int ans = sol.findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}