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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        if (root==NULL)return true;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    level.push_back(node->left->val);
                    }
                else{
                level.push_back(INT_MIN);  // NULL mark
            }
                if(node->right){
                    q.push(node->right);
                    level.push_back(node->right->val);
                    }
                else{
                level.push_back(INT_MIN);  // NULL mark
            }
               
            }
            int  sz=level.size();
            for(int i=0;i<sz/2;i++){
               if(level[i]!=level[sz-i-1]) return false;
            }
        }
        return true;
    }
};