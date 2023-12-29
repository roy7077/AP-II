/*----------------Method-1--------------*/
// MEMOIZATION
class Solution {
    public:
    int help(vector<int>& p,int i,int flag,vector<vector<int>>& memo,int& fee)
    {
        //base case
        if(i>=p.size())
        return 0;
        
        //memo check
        if(memo[i][flag]!=-1)
        return memo[i][flag];
        
        //Recursive calls
        //small calculation
        if(!flag)
        {
            int a=help(p,i+1,flag,memo,fee);
            int b=-p[i]+help(p,i+1,1,memo,fee)-fee;
            return memo[i][flag]=max(a,b);
        }
        
        if(flag)
        {
            int a=help(p,i+1,flag,memo,fee);
            int b=p[i]+help(p,i+1,0,memo,fee);
            return memo[i][flag]=max(a,b);
        }
        
        return -1;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> memo(prices.size(),vector<int>(2,-1));
        int ans=help(prices,0,0,memo,fee);
        return ans;
    }
};

/*----------------Method-2--------------*/
//TABULATION
class Solution {
    public:
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(!j)
                {
                    int a=prices[i]+dp[i+1][1];
                    int b=dp[i+1][0];
                    dp[i][j]=max(a,b);
                }
                else
                {
                    int a=dp[i+1][1];
                    int b=-prices[i]+dp[i+1][0]-fee;
                    dp[i][j]=max(a,b);
                }
            }
        }
        return dp[0][1];
    }
};

/*----------------Method-3--------------*/
//SPACE OPTIMIZED
class Solution {
    public:
    int maxProfit(vector<int>& prices,int fee) {
        vector<int> next(2,0);
        int n=prices.size();
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(2,0);
            for(int j=0;j<=1;j++)
            {
                if(!j)
                {
                    int a=prices[i]+next[1];
                    int b=next[0];
                    curr[j]=max(a,b);
                }
                else
                {
                    int a=next[1];
                    int b=-prices[i]+next[0]-fee;
                    curr[j]=max(a,b);
                }
            }
            next=curr;
        }
        return next[1];
    }
};

