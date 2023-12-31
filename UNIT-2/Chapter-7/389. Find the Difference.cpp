/*------------Method-1--------------*/
// Using hashmap
//Time complexity - O(N)
//Space complexity- O(N)

class Solution {
    public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        for(auto it:t)
        {
            if(mp[it]<=0)
            return it;
            
            mp[it]--;
        }
        
        return '1';
    }
};

/*------------Method-2--------------*/
// Using sorting
//Time complexity - O(NLogN)
//Space complexity- O(1)

class Solution {
    public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i])
            return t[i];
        }
        
        return t[t.length()-1];
    }
};