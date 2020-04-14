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
public:
    
    int heightOfTree(TreeNode * root ,int &diameter){
        if(root==NULL)return 0;
        
        int leftHeight=heightOfTree(root->left,diameter);
        int rightHeight=heightOfTree(root->right,diameter);
        
        diameter=max(diameter,leftHeight+rightHeight+1);
        
        return max(leftHeight,rightHeight)+1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int diameter=INT_MIN;
        heightOfTree(root,diameter);
        return diameter-1;
        
    }
};