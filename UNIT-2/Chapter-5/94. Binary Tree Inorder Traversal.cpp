// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    void help(TreeNode* root,vector<int>& ans)
    {
        if(!root)
        return ;
        
        help(root->left,ans);
        ans.push_back(root->val);
        help(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
};
