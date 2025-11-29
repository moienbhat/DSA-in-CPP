#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
private:
    // Function to find the largest rectangle area
    int largestRectangleArea(vector<int> &heights) {
        
        int n = heights.size(); // Size of array
        
        // Stack 
        stack<int> st;
        
        // To store largest area
        int largestArea = 0;
        
        // To store current area
        int area;
        
        /* To store the indices of next 
        and previous smaller elements */
        int nse, pse;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements is not the smaller element */
            while(!st.empty() && 
                  heights[st.top()] >= heights[i]){
                      
                // Get the index of top of stack
                int ind = st.top(); 
                st.pop();
                
                /* Update the index of 
                previous smaller element */
                pse = st.empty() ? -1 : st.top();
                
                /* Next smaller element index for 
                the popped element is current index */
                nse = i;
                
                // Calculate the area of the popped element
                area = heights[ind] * (nse-pse-1);
                
                // Update the maximum area
                largestArea = max(largestArea, area);
            }
            
            // Push the current index in stack
            st.push(i);
        }
        
        // For elements that are not popped from stack
        while(!st.empty()) {
            
            // NSE for such elements is size of array
            nse = n;
            
            // Get the index of top of stack
            int ind = st.top(); 
            st.pop();
            
            // Update the previous smaller element
            pse = st.empty() ? -1 : st.top();
            
            // Calculate the area of the popped element
            area = heights[ind] * (nse-pse-1);
            
            // Update the maximum area
            largestArea = max(largestArea, area);
        }
        
        // Return largest area found
        return largestArea;
    }
    
public:
    /* Function to find the largest 
    rectangle area containing all 1s */ 
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
        
        // Determine the size of matrix
        int n = matrix.size();
        int m = matrix[0].size();
        
        /* Prefix sum matric to store heights 
        for different ground levels */
        vector<vector<int>> prefixSum(n, vector<int>(m));
        
        // Fill up the prefix sum matrix column wise
        for(int j=0; j < m; j++) {
            int sum = 0;
            
            for(int i=0; i < n; i++) {
                sum += matrix[i][j];
                
                // If there is no base present
                if(matrix[i][j] == 0) {
                    prefixSum[i][j] = 0;
                    sum = 0;
                }
                
                // Store the height
                prefixSum[i][j] = sum;
            }
        }
        
        // To store the maximum area
        int maxArea = 0;
        
        // Traverse for different levels of ground
        for(int i = 0; i < n; i++) {
            
            // Get the largest area for current level
            int area = largestRectangleArea(prefixSum[i]);
            
            // Update the maximum area
            maxArea = max(area, maxArea);
        }
        
        // Return the maximum area
        return maxArea;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the largest 
    rectangle area containing all 1s */
    int ans = 
        sol.maximalAreaOfSubMatrixOfAll1(matrix);
    
    cout << "The largest rectangle area containing all 1s is: " << ans;
    return 0;
}