// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(auto it:stones)
        mp[it]++;
        
        int ans=0;
        for(auto it:jewels)
        ans+=mp[it];
        
        return ans;
    }
};