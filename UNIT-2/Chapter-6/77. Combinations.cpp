class Solution {
    public:
    void help(vector<vector<int>>& ans,int n,int k,vector<int>& v)
    {
        //base case
        if(n==0 or k==0)
        {
            if(k==0)
            ans.push_back(v);
            
            return ;
        }
    
        //recursive calls
        //small calculation
        help(ans,n-1,k,v);
        v.push_back(n);
        help(ans,n-1,k-1,v);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        help(ans,n,k,v);
        return ans;
    }
};