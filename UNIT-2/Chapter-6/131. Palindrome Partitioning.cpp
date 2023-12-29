class Solution {
public:
    
    bool is_palindrome(string str)
    {
        int s=0;
        int e=str.length()-1;
        while(s<=e)
        {
            if(str[s]!=str[e])
                return false;
            
            s++;
            e--;
        }
        return true;
    }
    
    void partition_helper(vector<vector<string>>& ans,vector<string> strv,string str)
    {
        if(str.length()==0)
        {
            ans.push_back(strv);
            return ;
        }
        
        for(int i=0;i<str.length();i++)
        {
            vector<string> temp;
            if(is_palindrome(str.substr(0,i+1)))
            {
                strv.push_back(str.substr(0,i+1));
                partition_helper(ans,strv,str.substr(i+1));
                strv.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        
             vector<vector<string>> v;
             vector<string> strv;
             partition_helper(v,strv,s);
             return v;
            
        }     
        
        
};