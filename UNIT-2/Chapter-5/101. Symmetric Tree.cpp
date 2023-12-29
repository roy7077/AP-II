// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    bool help(TreeNode* root1,TreeNode* root2)
    {
        //base cases
        if((!root1 and root2) or (root1 and !root2))
        return 0;
        
        if(!root1 and !root2)
        return 1;
        
        if(root1->val != root2->val)
        return 0;
        
        //recursive calls
        bool a=help(root1->left,root2->right);
        if(!a)
        return 0;
        
        bool b=help(root1->right,root2->left);
        return b;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return 1;
        
        return help(root->left,root->right);
    }
};
