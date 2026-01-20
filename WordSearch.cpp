#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    // Function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        // Get number of rows
        int rows = board.size();
        // Get number of columns
        int cols = board[0].size();

        // Loop through every cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start DFS if first letter matches
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        // If no path found, return false
        return false;
    }

private:
    // DFS function to search for the word
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // If all characters matched, return true
        if (idx == word.size()) return true;

        // Check boundaries and character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        // Store current character and mark as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all four directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

        // Restore the character (backtracking)
        board[i][j] = temp;

        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << sol.exist(board, "ABCCED") << endl; // true
    cout << boolalpha << sol.exist(board, "SEE") << endl;    // true
    cout << boolalpha << sol.exist(board, "ABCB") << endl;   // false
}