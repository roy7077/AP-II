typedef pair<int, int> pi;
class Solution {
    public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        adj[it[0]].push_back({it[1],it[2]});
        
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int d=it.first;
            int node=it.second;
            
            for(auto x:adj[node])
            {
                if(dist[x.first]>(d+x.second))
                {
                    dist[x.first]=d+x.second;
                    pq.push({d+x.second,x.first});
                }
            }
        }
        
        int maxi=-1;
        for(int i=1;i<=n;i++)
        maxi=max(maxi,dist[i]);
        
        return maxi>=1e9 ? -1:maxi;
    }
};