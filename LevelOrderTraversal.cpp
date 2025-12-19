#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform level order traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

// Helper function to build a binary tree level-wise using input
TreeNode* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;
    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->val << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    cout << "Build your binary tree:\n";
    TreeNode* root = buildTree();

    vector<vector<int>> result = levelOrder(root);

    cout << "\nLevel Order Traversal:\n";
    for (auto level : result) {
        for (auto val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
