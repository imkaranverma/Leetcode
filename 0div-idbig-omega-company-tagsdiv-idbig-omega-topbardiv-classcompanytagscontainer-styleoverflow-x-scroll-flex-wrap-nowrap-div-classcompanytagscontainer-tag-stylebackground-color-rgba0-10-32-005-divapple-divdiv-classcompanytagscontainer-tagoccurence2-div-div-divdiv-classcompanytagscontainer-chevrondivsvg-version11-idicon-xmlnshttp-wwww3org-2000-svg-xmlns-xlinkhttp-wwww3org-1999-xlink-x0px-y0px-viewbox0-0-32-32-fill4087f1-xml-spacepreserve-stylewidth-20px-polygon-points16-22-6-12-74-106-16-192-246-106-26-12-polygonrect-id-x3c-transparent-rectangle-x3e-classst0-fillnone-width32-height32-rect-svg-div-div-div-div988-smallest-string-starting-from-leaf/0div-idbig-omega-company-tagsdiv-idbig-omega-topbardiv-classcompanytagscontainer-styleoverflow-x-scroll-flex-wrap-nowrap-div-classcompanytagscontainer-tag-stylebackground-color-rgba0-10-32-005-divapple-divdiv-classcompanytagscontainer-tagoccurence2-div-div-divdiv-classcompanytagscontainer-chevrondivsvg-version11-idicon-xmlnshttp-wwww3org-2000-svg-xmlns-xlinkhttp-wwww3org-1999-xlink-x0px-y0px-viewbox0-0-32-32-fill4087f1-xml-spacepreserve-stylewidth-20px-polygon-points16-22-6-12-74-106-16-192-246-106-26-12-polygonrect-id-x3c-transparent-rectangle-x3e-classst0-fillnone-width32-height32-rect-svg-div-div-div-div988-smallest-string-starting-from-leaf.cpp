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
   
    string wrd = "";

    void findlex(TreeNode* root, string s){
        s = (char)(root->val + 97) + s;
        if(!root->left && !root->right){
          
            if(wrd!=""){
                wrd = min(wrd,s);
            }else{
                wrd = s;
            }
            return;
        }
        if(root->left)
            findlex(root->left, s);
        if(root->right)
            findlex(root->right, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        findlex(root, "");
        return wrd;
    }
};