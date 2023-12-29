// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution {
    public:
    bool help(TreeNode* p,TreeNode* q)
    {
        //base cases
        if((!p and q) or (p and !q))
        return 0;
        
        if(!p and !q)
        return 1;
        
        if(p->val != q->val)
        return 0;
        
        //recursive calls
        bool left=help(p->left,q->left);
        if(!left)
        return 0;
        
        bool right=help(p->right,q->right);
        return right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return help(p,q);
    }
};