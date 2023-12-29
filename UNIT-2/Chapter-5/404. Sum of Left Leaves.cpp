// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    int help(TreeNode* root,bool flag)
    {
        if(!root)
        return 0;
        
        if(flag and root->left==NULL and root->right==NULL)
        return root->val;
        
        int left=help(root->left,1);
        int right=help(root->right,0);
        
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return help(root,0);
    }
};