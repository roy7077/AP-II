/*--------------Method-1----------*/
// RECURSION
class Solution {
    public:
    bool help(vector<int>& nums,int s,int e,int sum1,int sum2,bool flag)
    {
        //base case
        if(s>e)
        {
            if(sum1>=sum2)
            return 1;
            else
            return 0;
        }
        
        //recursive call
        //small calculation
        if(flag)
        {
            bool a=help(nums,s,e-1,sum1+nums[e],sum2,!flag);
            bool b=help(nums,s+1,e,sum1+nums[s],sum2,!flag);
            
            return a or b;
        }
        else
        {
            bool a=help(nums,s,e-1,sum1,sum2+nums[e],!flag);
            bool b=help(nums,s+1,e,sum1,sum2+nums[s],!flag);
            
            return a and b;
        }
        
        return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        return help(nums,0,nums.size()-1,0,0,1);
    }
};

/*--------------Method-2----------*/
// TABULATION
class Solution {
    public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int total = 0;
        for(int i =0;i<n;i++) {
            total += nums[i];
        }
        
        for(int len = 1;len<=n;len++) 
        {
            for(int i = 0;i<= n-len;i++) 
            {
                int j = i + len - 1;
                int a = (i+1 < n && j-1 >= 0) ? dp[i+1][j-1] : 0;
                int b = (i+2 < n) ? dp[i+2][j] : 0;
                int c = (j-2 >= 0) ? dp[i][j-2] : 0;
                
                dp[i][j] = max(nums[i] + min(a, b), nums[j] + min(a,c));
            }
        }
        
        int player1Score = dp[0][n-1];
        int player2Score = total - player1Score;
        return player1Score >= player2Score;
    }
};