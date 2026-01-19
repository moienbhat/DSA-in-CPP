#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // Function to check if substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        // Loop while start < end
        while (start < end) {
            // If mismatch, not a palindrome
            if (s[start] != s[end]) return false;
            // Move pointers inward
            start++;
            end--;
        }
        // All characters matched
        return true;
    }

    // Backtracking function to build partitions
    void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &res) {
        // If index reaches end of string, store current partition
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        // Try all possible substrings
        for (int i = index; i < s.length(); i++) {
            // If substring is a palindrome
            if (isPalindrome(s, index, i)) {
                // Add substring to current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur for remaining string
                backtrack(i + 1, s, path, res);
                // Backtrack to try other partitions
                path.pop_back();
            }
        }
    }

    // Main function to return all palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);
    for (auto &vec : ans) {
        for (auto &str : vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
