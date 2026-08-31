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
private:
TreeNode* handlechild(TreeNode* root){
    if(root->left==NULL){    // if only one children is there , no left
        return root->right;
    }
    else if(root->right==NULL){  // No right child
        return root->left;
    }
    else{                  // HAving both left and right children 
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlastright(root->left);
        lastright->right=rightchild;
        return root->left;
    }

}

TreeNode* findlastright(TreeNode* root){  // Goes to RightMost node of 
    if(root->right==NULL) {               //left subtree
        return root;
    }
    return findlastright(root->right);

}
public:  // this function just finds the node which is just behind the key
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL; 
        if(root->val==key) return handlechild(root); // only one node

        TreeNode* dummy=root;  // root will traverse 
        while(root!=NULL){
            if(root->val > key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=handlechild(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=handlechild(root->right);
                    break;
                }
                else{
                    root=root->right;
                }

            }    
        }
            return dummy;

    }
};
