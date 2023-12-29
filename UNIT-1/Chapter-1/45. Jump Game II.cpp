/*-------------------MEMOIZATION----------------*/
class Solution {
    public:
    int help(vector<int>& nums,int& n,int i,vector<int>& memo)
    {
        //base case
        if(i==n-1)
        return 0;
        
        if(i>=n)
        return 1e9;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        //small calculation
        int step=1e9;
        for(int j=nums[i];j>=1;j--)
        {
            if(i+j<n)
            {
                int temp=1+help(nums,n,i+j,memo);
                step=min(step,temp);
            }
        }
        return memo[i]=step;
    }
    int jump(vector<int>& nums) {
        
        vector<int> memo(nums.size(),-1);
        int n=nums.size();
        int ans=help(nums,n,0,memo);
        
        if(ans>=1e9)
        return -1;
        else
        return ans;
    }
};



/*-------------------TABULATION----------------*/
class Solution {
    public:
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        int n=nums.size();
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--)
        {
            int step=1e9;
            for(int j=nums[i];j>=1;j--)
            {
                if(i+j<n)
                {
                    int temp=1+dp[i+j];
                    step=min(step,temp);
                }
            }
            dp[i]=step;
        }
        
        return dp[0]>=1e9 ? -1:dp[0];
    }
};



/*-------------------SPACE OPTIMIZED----------------*/
class Solution {
    public:
    int jump(vector<int>& nums) {
        
       int n=nums.size();
       if(n==0 or n==1) 
       return 0;
       
       if(nums[0]==0) 
       return -1;
       
       int maxReach=nums[0];
       int steps=nums[0];
       int jumps=0;
       
       for(int i=1;i<n;i++){
           
           if(i==n-1) 
           return jumps+1;
           
           steps--;
           maxReach=max(maxReach,nums[i]+i);
           if(steps==0)
           {
               if(i==maxReach) 
               return -1;
               
               jumps++;
               steps=maxReach-i;
           }
       }
      return 0;
    }
};
