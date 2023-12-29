/*------------------Method-1--------------*/
// MEMOIZATION
class Solution {
    public:
    int help(int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i==0 and j==0)
        return 1;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        int a,b;
        a=b=0;
        
        if(i-1>=0)
        a=help(i-1,j,memo);
        
        if(j-1>=0)
        b=help(i,j-1,memo);
        
        return memo[i][j]=a+b;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return help(m-1,n-1,memo);
    }
};


/*------------------Method-2--------------*/
// TABULATION 
class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {   
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                continue;
                
                int a,b;
                a=b=0;
                
                if(i-1>=0)
                a=dp[i-1][j];
                
                if(j-1>=0)
                b=dp[i][j-1];
                
                dp[i][j]=a+b;
            }
        }
        return dp[m-1][n-1];
    }
};

/*------------------Method-3--------------*/
// SPACE OPTIMIZED 
class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                int a,b;
                a=b=0;

                if(j-1>=0)
                a=curr[j-1];

                if(i-1>=0)
                b=pre[j];

                curr[j]=a+b;
            }
            pre=curr;
        }
         return pre[n-1];
        }
};