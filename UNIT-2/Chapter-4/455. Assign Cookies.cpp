// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1;
        int j=s.size()-1;
        int cnt=0;
        
        while(i>=0 and j>=0)
        {
            if(s[j]>=g[i])
            {
                cnt++;
                j--;
            }
            i--;
        }
        return cnt;
    }
};