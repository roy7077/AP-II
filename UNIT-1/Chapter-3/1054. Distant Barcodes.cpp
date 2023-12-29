// Time complexity - O(NloN)
// Space complexity- O(2*N)
class Solution {
    public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto it:bar)
        mp[it]++;
        
        for(auto it:mp)
        pq.push({it.second,it.first});
        
        int pos=0;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int cnt=top.first;
            
            for(int i=0;i<cnt;i++)
            {
                bar[pos]=top.second;
                pos+=2;
                
                if(pos>=bar.size())
                pos=1;
            }
        }
        return bar;
    }
};