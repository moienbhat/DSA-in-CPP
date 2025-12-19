#include <iostream>
#include <vector> 
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class with postorder function
class Solution {
public:
    void postorderTraversal(TreeNode* root, vector<int>& result) {
        // Base case: if node is null
        if (!root) return;

        // Traverse left subtree
        postorderTraversal(root->left, result);

        // Traverse right subtree
        postorderTraversal(root->right, result);

        // Add current node value
        result.push_back(root->val);
    }
};

// Main function
int main() {
    // Build tree:    1
    //              /   \
    //             2     3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Object of solution
    Solution sol;
    vector<int> result;

    // Call postorder traversal
    sol.postorderTraversal(root, result);

    // Print result
    for (int val : result) cout << val << " ";
    return 0;
}