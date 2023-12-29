// Time complexity - O(N)
// Space complexity- O(height of tree)
typedef pair<int,int> pi;
class Solution {
    public:
    pi help(TreeNode* root)
    {
        //base case
        if(!root)
        return {0,0};
        
        //recursive calls & small calculation
        pi left=help(root->left);
        pi right=help(root->right);
        
        pi pf;
        pf.first=left.first+right.first+root->val;
        pf.second=abs(left.first-right.first)+left.second+right.second;
            
        return pf;
    }
    int findTilt(TreeNode* root) {
        return help(root).second;
    }
};
