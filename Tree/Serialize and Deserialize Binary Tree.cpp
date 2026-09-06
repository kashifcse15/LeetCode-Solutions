/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if(root == NULL) return "";
    string ans = "";
    queue<TreeNode*> q;
    q.push(root);
    q.pop();
    while(!q.empty()) {
        TreeNode* node = q.front();
        
        if(node == NULL) {
            ans += "# ";
        }
        else {
            ans += to_string(node->val) + " ";
            q.push(node->left);
            q.push(node->right);
        }
    }

    return ans;  //1 2 3 # # 4 5 # # # #
}

    
