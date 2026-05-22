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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        TreeNode* node= root;

        while(node){
            int  nodevalue=node->val;
            if(nodevalue<val ){
                node=node->right;
            }
            else if(nodevalue==val)return node;
            else if(nodevalue>val){
                node=node->left;
            }
        }
        return NULL;
        
    }
};