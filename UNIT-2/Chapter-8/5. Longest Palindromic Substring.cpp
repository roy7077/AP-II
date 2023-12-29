// Space complexity- O(1)
class Solution {
public:
    
    int help(string& S,int l,int r)
    {
        while(l>=0 and r<S.length() and S[l]==S[r])
        {
            l--;
            r++;
        }
        
        return r-l-1;
    }
    string longestPalindrome(string S) {
       int maxi=0;
        int index=0;
        
        for(int i=0;i<S.length();i++)
        {
            int l1=help(S,i,i);
            int l2=help(S,i,i+1);
            
            l1=max(l1,l2);
            if(l1>maxi)
            {
                maxi=l1;
                index=i-(l1-1)/2;
            }
        }
        
        return S.substr(index,maxi); 
    }
};