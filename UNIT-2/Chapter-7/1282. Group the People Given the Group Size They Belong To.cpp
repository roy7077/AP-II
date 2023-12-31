// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<g.size();i++)
        mp[g[i]].push_back(i);
        
        vector<vector<int>> ans;
        for(auto it:mp)
        {
            int size=it.first;
            int i=0;
            while(i<it.second.size())
            {
                int cnt=0;
                vector<int> temp;
                while(cnt<size)
                {
                    temp.push_back(it.second[i]);
                    i++;
                    cnt++;
                }
                
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
