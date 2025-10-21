#include<iostream>
using namespace std;

class Solution {
    public:
    vector<int> divisors(int n) {
        vector<int> ans;

        int sqrtN = sqrt(n);
        for(int i=1; i<= sqrtN; i++) {
            if(n % i == 0) {
                ans.push_back(i);
                if( i != n / i) {
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin() , ans.end());

        return ans;
    }
};
int main() {
    int n = 6;

    Solution sol;

    vector<int> ans = sol.divisors(n);

    cout<<"The divisors of "<< n << " are : ";
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i] << " ";
    }
    return 0;
}