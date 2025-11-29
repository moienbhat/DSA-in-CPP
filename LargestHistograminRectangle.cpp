#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
    public:
    int largestRectangleArea(vector <int> &heights) {
        stack <int> st; 
        int maxArea = 0; 
        int n = heights.size();
        
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3,1};
    Solution sol;
    cout<< "The largest area in Histogram is : "<<sol.largestRectangleArea(heights)<<endl;

    return 0;
}