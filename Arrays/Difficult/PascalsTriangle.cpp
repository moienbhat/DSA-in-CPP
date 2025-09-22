#include <iostream>
#include <vector>
using namespace std;

long long nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    // Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back((int)nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";  // fixed
    }
    return 0;
}
