/*------------------Method-1--------------*/
// MEMOIZATION
class Solution {
    public:
    int help(int n,vector<int>& memo)
    {
        //base case
        if(n==0)
        return 1;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        int a=help(n-1,memo);
        int b=0;
        if(n-2>=0)
        b=help(n-2,memo);
        
        return memo[n]=a+b;
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return help(n,memo);
    }
};

/*------------------Method-2--------------*/
// TABULATION 
class Solution {
    public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int a=dp[i-1];
            int b=dp[i-2];
            
            dp[i]=a+b;
        }
        return dp[n];
    }
};

/*------------------Method-3--------------*/
// SPACE OPTIMIZED 
class Solution {
    public:
    int climbStairs(int n) {
        int pre1=1;
        int pre2=1;
        for(int i=2;i<=n;i++)
        {
            int curr=pre1+pre2;
            pre2=pre1;
            pre1=curr;
        }
        return pre1;
    }
};