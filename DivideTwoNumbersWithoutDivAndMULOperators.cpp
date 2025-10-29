#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = (dividend > 0) == (divisor > 0);

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long quotient = 0;

        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        return sign ? quotient : -quotient;
    }
};

int main() {
    Solution sol;

    cout << "10 / 3 = " << sol.divide(10, 3) << endl;
    cout << "7 / -3 = " << sol.divide(7, -3) << endl;
    cout << "-10 / -2 = " << sol.divide(-10, -2) << endl;
    cout << "INT_MIN / -1 = " << sol.divide(INT_MIN, -1) << endl;
    cout << "INT_MIN / 1 = " << sol.divide(INT_MIN, 1) << endl;
    cout << "INT_MIN / INT_MIN = " << sol.divide(INT_MIN, INT_MIN) << endl;
    cout << "0 / 1 = " << sol.divide(0, 1) << endl;
    
    return 0;
}

















// int divide(int dividend. int divisor) {
//     if(dividend = divisor) returm 1;

//     bool sign  = true;
//     if(dividend >= 0 && divisor < 0) sign = false;
//     elseif(dividend <= 0 && divisor < 0) sign = false;

//     long n = abs(dividend);
//     long d = abs(divisor);
//     divisor = abs(divisor);
//     long quotient = =;

//     while(n >= d) {
//         int cnt = 0;
//         while(n >= (d <<< (cnt+1))) {
//             cnt+= 1;
//         }

//         quotient += 1<<cnt;
//         n -= (d << cnt);
//     }
//     if(quotient == (1<<31) && sign) {
//         return INT_MAX;
//     }

//     if(quotient == (1<<31) && !sign) {
//         return INT_MIN;
//     }
//     retun sign ? quotient : -quotient;
// }