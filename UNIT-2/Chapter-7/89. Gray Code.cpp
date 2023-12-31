// Time complexity - O(2^N)
// Space complexity- O(2^N)
class Solution {
    public:
    int number(string s)
    {
        int num=0;
        int cnt=1;
        int i=s.length()-1;
        while(i>=0)
        {
            if(s[i]=='1')
            num+=cnt;
            
            cnt*=2;
            i--;
        }
        return num;
    }
    void code(int n,vector<string>& v)
    {
        //base case
        if(n==1)
        {
            v.push_back("0");
            v.push_back("1");
            return ;
        }
        //recursive calls
        //small calculation
        code(n-1,v);
        int size=v.size();
        for(int i=size-1;i>=0;i--)
        {
            v.push_back(v[i]);
            v[i]="0"+v[i];
        }
        
        for(int i=size;i<v.size();i++)
        v[i]="1"+v[i];
        
    }
    vector<int> grayCode(int n) {
        vector<string> v;
        code(n,v);
        
        vector<int> ans;
        for(auto it:v)
        {
            int num=number(it);
            ans.push_back(num);
        }
        
        return ans;
    }
};
