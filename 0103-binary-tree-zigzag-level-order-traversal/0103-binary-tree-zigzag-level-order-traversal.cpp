class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; 
        while (!q.empty()) {
            int size = q.size();
            vector<int> ziglevel(size); 
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                
                int index = leftToRight ? i : (size - 1 - i);
                ziglevel[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            ans.push_back(ziglevel);
            leftToRight = !leftToRight; // Flip direction for the next level
        }
        
        return ans;
    }
};