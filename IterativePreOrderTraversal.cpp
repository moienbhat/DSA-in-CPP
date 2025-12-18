#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative Preorder Traversal
vector<int> preOrderTraversal(TreeNode *root) {
    vector<int> preorder;
    if (root == NULL) return preorder;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        preorder.push_back(node->val);

        if (node->right != NULL) st.push(node->right);
        if (node->left != NULL) st.push(node->left);
    }

    return preorder;
}

// Helper function to build a binary tree level-wise
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
        if (!(cin >> leftVal)) {
            cout << "Invalid input. Exiting.\n";
            return root;
        }

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for NULL): ";
        if (!(cin >> rightVal)) {
            cout << "Invalid input. Exiting.\n";
            return root;
        }

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

    vector<int> preorder = preOrderTraversal(root);

    cout << "\nPreorder Traversal: ";
    for (int val : preorder) cout << val << " ";
    cout << endl;

    return 0;
}
