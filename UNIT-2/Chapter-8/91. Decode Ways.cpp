/*------------------Method-1--------------*/
// MEMOIZATION 
class Solution {
    public:
    int help(string& s,int i,vector<int>& memo)
    {
        //base case
        if(i>=s.length())
        return 1;
        
        if(i==s.length()-1)
        {
            if(s[i]=='0')
            return 0;
            else
            return 1;
        }
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        //small calculation
        if(s[i]=='0')
        return 0;
        
        int a=help(s,i+1,memo);
        int b=0;
        int temp=(s[i]-48)*10;
        temp+=(s[i+1]-48);
        
        if(temp<=26)
        b=help(s,i+2,memo);
        
        return memo[i]=(a+b);
    }
    
    int numDecodings(string s) {
        vector<int> memo(s.length()+1,-1);
       int ans=help(s,0,memo);
       return ans;
    }
};

/*------------------Method-2--------------*/
// TABULATION 
class Solution {
    public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,1);
        if(s[n-1]=='0')
        dp[n-1]=0;
        else
        dp[n-1]=1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            
            int a,b;
            a=b=0;
            
            a=dp[i+1];
            int temp=(s[i]-48)*10;
            temp+=(s[i+1]-48);

            if(temp<=26)
            b=dp[i+2];
            
            dp[i]=(a+b);
        }
        return dp[0];
    }
};


/*------------------Method-3--------------*/
// SPACE OPTIMIZED 
class Solution {
    public:
    int numDecodings(string s) {
        int n=s.length();
        int next=1;
        int secondnext=1;
        
        if(s[n-1]=='0')
        next=0;
        else
        next=1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                secondnext=next;
                next=0;
                continue;
            }
            
            int a,b;
            a=b=0;
            
            a=next;
            int temp=(s[i]-48)*10;
            temp+=(s[i+1]-48);

            if(temp<=26)
            b=secondnext;
            
            int curr=a+b;
            secondnext=next;
            next=curr;
        }
        return next;
    }
};