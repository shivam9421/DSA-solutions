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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>>vertical;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){ 
            auto ele=q.front();
            q.pop();
            TreeNode* node=ele.first;
            int row=ele.second.first;
            int col=ele.second.second;
            vertical[col][row].insert(node->val);
            if(node->left)q.push({node->left,{row+1,col-1}});
            if(node->right)q.push({node->right,{row+1,col+1}});
            
        }

        for(auto p: vertical){
            vector<int> columnvector;
            for(auto q:p.second){
                columnvector.insert(columnvector.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(columnvector);
        }
        return ans ;
    }
};