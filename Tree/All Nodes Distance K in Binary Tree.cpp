/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
void findparent(unordered_map<TreeNode*, TreeNode*>&parent, TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();
        if(current->left){
            parent[current->left]=current;
            q.push(current->left);
        }
         if(current->right){
            parent[current->right]=current;
            q.push(current->right);
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        findparent(parent,root);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int currdist=0;
        while(!q.empty()){
            int size=q.size();
            if(currdist==k) break;
            currdist++;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();

            if(current->left && !visited[current->left]){
                visited[current->left]=true;
                q.push(current->left);
            }
            if(current->right && !visited[current->right]){
                visited[current->right]=true;
                q.push(current->right);
            }
            if(parent[current] && !visited[parent[current]]){
                visited[parent[current]]=true;
                q.push(parent[current]);
            }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* current=q.front();
            
            result.push_back(current->val);
        }
        return result;
    }
};;
