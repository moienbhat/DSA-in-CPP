#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include<numeric>

using namespace std;


bool searchMatrix(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = (m*n) - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if(mat[row][col] == target) {
            return true;
        }

        else if(mat[row][col] < target) {
            low = mid + 1;
        }
        else {
            high = mid  -1;
        }
    }
    return false;
}


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}