// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    bool help(TreeNode* root,int target)
    {
        //base case
        if(!root)
        return 0;
            
        //recursive calls & small calculation
        if(root->left==NULL and root->right==NULL and target-(root->val)==0)
        return 1;
        
        int left=help(root->left,target-(root->val));
        if(left)
        return 1;
        
        int right=help(root->right,target-(root->val));
        return right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root,targetSum);
    }
};