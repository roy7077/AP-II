class Solution {
    public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> adj(n);
        // create a adjancent list
        for(auto &i:flights){
            adj[i[0]].emplace_back(i[1],i[2]);
        }
        // distance vector for distances from source to different nodes.
        vector<int> distance(n,INT_MAX);
        // assign the source distance as zero
        distance[src] = 0;
        // a queue with path as {distance and source}
        queue<pair<int,int>> q;
        q.push({0,src});
        int steps = 0;
        // do bfs while queue is not empty or under we move k stops
        while(!q.empty() && steps < k+1)
        {
            int size = q.size();
            while(size--)
            {
                auto p =q.front();
                q.pop();
                int dist = p.first, d = p.second;
                // find the neighbor city
                for(auto &[v,wt] : adj[d])
                {
                    // check if it is the one minimum cost
                    int cost = dist + wt;
                    if(cost > distance[v])
                        continue;
                    // else update cost and push element to queue
                    distance[v] = cost;
                    q.push({distance[v],v});
                }
            }
            // increment the step with one as we move 1 step every while loop
            steps++;
        }
        // return -1 if we cannot reach the destination city within the k stops else return the minimum cost
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }  
};