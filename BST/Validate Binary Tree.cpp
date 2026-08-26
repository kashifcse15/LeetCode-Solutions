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


    bool solve(TreeNode* root, long long minVal, long long maxVal){
        if(root == NULL) return true;

        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

//ANOTHER METHOD
// bool isValidBST(TreeNode* root) {
    //     if(!root) return true;
    //     if(root->left!=NULL && root->left->val >= root->val) return false;
    //     if(root->right!=NULL && root->right->val <= root->val) return false;
    //     isValidBST(root->left);
    //     isValidBST(root->right);

    //     return true;
    // }
// };

    
