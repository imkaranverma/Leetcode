/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* root, int& val, int depth, char ch){
        if(root == NULL && depth != 0)return NULL;
        if(depth == 0){
            TreeNode* node = new TreeNode(val);
            if(ch == 'l')node->left = root;
            if(ch == 'r')node->right = root;
            return node;
        }

        TreeNode* leftnode = f(root->left, val, depth-1, 'l');
        TreeNode* rightnode = f(root->right, val, depth-1, 'r');

        if(leftnode != root->left)root->left = leftnode;
        if(rightnode != root->right)root->right = rightnode;

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return f(root, val, depth-1, '\0');
    }
};