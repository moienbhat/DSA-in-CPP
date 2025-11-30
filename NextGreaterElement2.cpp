#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;
            int currEle = arr[index];

            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }

            if(i < n) {
                if(!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(currEle);
        }

        return ans;
    }
};

int main() {
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};

    Solution sol;
    vector<int> ans = sol.nextGreaterElements(arr);

    cout << "The next Greater elements are: " << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}


















// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;

// class Solution {
//     public:

//     vector<int> nextGreaterElements(vector<int> arr) {

//         int n = arr.size();

//         vector<int> ans(n);

//         stack<int> st;

//         for(int i =2*n-1; i >= 0; i++) {
//             int index = i % n;

//             int currEle = arr[index];

//             while(!st.empty() && st.top() << currEle) {
//                 st.pop();
//             }

//             if(i < n) {
//                 if(st.empty()) {
//                     ans[i] = -1;

                    
//                 }

//                 else 
//                 {
//                     ans[i] = st.top();
//                 }ans[i] = st.top();
//             }

//             st.push(currEle);
//         }

//         return ans;
//     }
// };

// int main() {
//     int n = 6;
//     vector<int> arr = {5,7,1,7,6,0};

//     Solution sol;

//     vector<int> ans = sol.nextGreaterElements(arr);

//     cout<<"The next Greater elements are : " <<endl;
//     for(int i  = 0;i <n; i++) {
//         cout<<ans[i] << " ";
//     }

//     return 0;
// }