/*-------------------Method-1----------------*/
// Backtracking
class Solution {
    public:
    void help(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int>& v)
    {
        //base case
        if(i>=nums.size())
        {
            ans.push_back(v);
            return ;
        }
        
        //recursive calls
        //small calculation
        help(nums,i+1,ans,v);
        
        v.push_back(nums[i]);
        help(nums,i+1,ans,v);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        help(nums,0,ans,v);
        return ans;
    }
};


/*-------------------Method-2--------------*/
//Powerset
//Time complexity - O(2^N * N)
//Space complexity- O(N)
class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        for(int i=0;i<(1<<nums.size());i++)
        {
            vector<int> sub;
            for(int j=0;j<nums.size();j++)
            {
                if(i&(1<<j))
                sub.push_back(nums[j]);
            }
            output.push_back(sub);
        }

        return output;
    }
