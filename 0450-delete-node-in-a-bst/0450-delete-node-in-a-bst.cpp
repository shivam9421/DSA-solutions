class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        TreeNode* node=root;
        TreeNode* previousNode=NULL;
        int count=-1;
        while(node){
            int nodevalue=node->val;

            if(nodevalue<key){
                previousNode=node;        
                node=node->right;
                count=0;
            }
            else if(nodevalue>key){
                previousNode=node;        
                node=node->left;
                count=1;
            }
            else if(nodevalue==key && count==0){
                if(node->left==NULL && node->right==NULL){
                    previousNode->right=NULL;
                }
                else if(node->left==NULL){
                    previousNode->right=node->right;
                }
                else if(node->right==NULL){
                    previousNode->right=node->left;
                }
                else{
                    TreeNode* nodecntopreviousparent=node->left;
                    TreeNode* rightnode=node->right;
                    while(nodecntopreviousparent->right){
                        nodecntopreviousparent=nodecntopreviousparent->right;
                    }
                    nodecntopreviousparent->right=rightnode;
                    previousNode->right=node->left;
                }
                return root;
            }
            else if(nodevalue==key && count==1){
                if(node->left==NULL && node->right==NULL){
                    previousNode->left=NULL;
                }
                else if(node->left==NULL){
                    previousNode->left=node->right;
                }
                else if(node->right==NULL){
                    previousNode->left=node->left;
                }
                else{
                    TreeNode* nodecntopreviousparent=node->left;
                    TreeNode* rightnode=node->right;
                    while(nodecntopreviousparent->right){
                        nodecntopreviousparent=nodecntopreviousparent->right;
                    }
                    nodecntopreviousparent->right=rightnode;
                    previousNode->left=node->left;
                }
                return root;
            }
            else if(nodevalue==key && count==-1){
                
                if(node->left==NULL && node->right==NULL){
                    return NULL;
                }
                else if(node->left==NULL){
                    return node->right;
                }
                else if(node->right==NULL){
                    return node->left;
                }
                else{
                    TreeNode* nodecntopreviousparent=node->left;
                    TreeNode* rightnode=node->right;
                    while(nodecntopreviousparent->right){
                        nodecntopreviousparent=nodecntopreviousparent->right;
                    }
                    nodecntopreviousparent->right=rightnode;
                    return node->left;
                }
            }
        }
        return root;
    }
};