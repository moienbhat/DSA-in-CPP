


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  
        stack<int> st;


        for(int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];


            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) nge[i] = st.top();
            }

            st.push(curr);
        }
        return nge;
    }
};

int main() {
    Solution obj;
    vector<int> v = {5, 7, 1, 2, 6, 0};

    vector<int> res = obj.nextGreaterElement(v);

    cout << "The next Greater Elements are:" << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
