#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, int &count){
    if(root == NULL) {
        return;
    }
    count++;
    inorder(root->left, count);
    inorder(root->right, count);
}

int countnodes(TreeNode* root) {
    if(root == NULL) return 0;

    int count = 0;

    inorder(root, count);
    return count;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int totalNodes = countnodes(root);
    cout << "Total number of nodes in the complete binary tree: " << totalNodes << endl;
    return 0;
}