/*------------------Method-1--------------*/
// MEMOIZATION
class Solution {
    public:
    int help(vector<int>& nums,int i,vector<int>& memo)
    {
        //base case
        if(i<0)
        return 0;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        //small calculation
        int a,b;
        a=b=0;
        
        a=help(nums,i-1,memo);
        b=nums[i]+help(nums,i-2,memo);
        
        return memo[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
        return nums[0];
        
        int n=nums.size();
        vector<int> v1;
        vector<int> v2;
        vector<int> memo1(n,-1);
        vector<int> memo2(n,-1);
    
        for(int i=0;i<n-1;i++)
        v1.push_back(nums[i]);
        
        for(int i=1;i<n;i++)
        v2.push_back(nums[i]);
        
        int ans1=help(v1,n-2,memo1);
        int ans2=help(v2,n-2,memo2);
        
        return max(ans1,ans2);
    }
};


/*------------------Method-2--------------*/
// TABULATION 
class Solution {
    public:
    int help(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int a=dp[i-1];
            int b=nums[i];
            if(i-2>=0)
            b+=dp[i-2];
            
            dp[i]=max(a,b);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
        return nums[0];
        
        int n=nums.size();
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0;i<n-1;i++)
        v1.push_back(nums[i]);
        
        for(int i=1;i<n;i++)
        v2.push_back(nums[i]);
        
        int ans1=help(v1);
        int ans2=help(v2);
        
        return max(ans1,ans2);
    }
};

/*------------------Method-3--------------*/
// SPACE OPTIMIZED 
class Solution {
    public:
    int DP(vector<int>& nums,int l,int r)
    {
        int dp0=0,dp1=0,temp; //dp0,dp0 maintain the last two dp state
        for(int i=l;i<=r;i++)
        {
            temp=dp0;
            dp0=max(dp1+nums[i],dp0);
            dp1=temp;
        }
        return max(dp0,dp1);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) 
        return nums[0];
        
        return max(DP(nums,0,n-2),DP(nums,1,n-1));
    }
};