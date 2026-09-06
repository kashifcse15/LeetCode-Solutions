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

// Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size() == 0) return NULL;
        stringstream ss(data);
        string str;
        ss >> str;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // LEFT CHILD
        ss >> str;
        if(str != "#") {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
            }
            // RIGHT CHILD
            ss >> str;
            if(str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

    
