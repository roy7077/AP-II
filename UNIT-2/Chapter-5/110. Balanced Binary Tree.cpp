// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<int, int> pi; 
class Solution {
    public:
    pi help(TreeNode* root)
    {
        //base case
        if(!root)
        return {0,1};
        
        //recursive calls & small calculation
        pi a=help(root->left);
        if(!a.second)
        return {0,0};
        
        pi b=help(root->right);
        if(!b.second)
        return {0,0};
        
        if(abs(a.first-b.first)<=1)
        return {max(a.first,b.first)+1,1};
        
        return {};
    }
    bool isBalanced(TreeNode* root) {
        return help(root).second;
    }
};