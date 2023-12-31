class Solution {
    public:
    int help(int n,int k)
    {
        //base case
        if(n==1)
        return 0;
        
        //recursive calls
        //small calculation
        int len=pow(2,n-1);
        if(k<=(len/2))
        return help(n-1,k);
        else
        return !help(n-1,k-(len/2));
    }
    
    int kthGrammar(int n, int k) {
        return help(n,k);
    }
};