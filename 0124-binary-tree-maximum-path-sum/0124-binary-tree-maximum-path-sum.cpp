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
    int height(TreeNode* root,int &maxpathsum){
        if(!root) return 0;
        int ltsum=max(0,height(root->left,maxpathsum));
        int rtsum=max(0,height(root->right,maxpathsum));
        int sum=ltsum+rtsum+(root->val);
        maxpathsum=max(maxpathsum,sum);
        int  maxleft= ltsum+root->val;
        int  maxright=rtsum+root->val;
        return max(maxleft,maxright);
    } 
    int maxPathSum(TreeNode* root) {
        int  maxpathsum=INT_MIN;
        height(root,maxpathsum);
        return maxpathsum;
        
    }
};