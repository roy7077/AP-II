/*-------------Method-1---------*/
//using breadth first search algorithm (BFS)
class Solution {
    public:
    bool bfs(vector<vector<int>>& graph,int node,bool c,vector<int>& col)
    {
        queue<int> q;
        q.push(node);
        col[node]=c;
        
        while(!q.empty())
        {
            int node=q.front();
            c=col[node];
            q.pop();
            
            for(auto it:graph[node])
            {
                if(col[it]==-1)
                {
                    col[it]=int(!c);
                    q.push(it);
                }
                else if(col[it]==c)
                return 0;
            }
        }
        
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()+1,-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                bool ans=bfs(graph,i,0,color);
                if(!ans)
                return 0;
            }
        }
        return 1;
    }
};

/*-------------Method-2---------*/
//using depth first search algorithm (DFS)
class Solution {
    public:
    bool help(vector<vector<int>>& graph,int node,bool c,vector<int>& col)
    {
        col[node]=int(c);
        for(auto it:graph[node])
        {
            if(col[it]==-1)
            {
                bool ans=help(graph,it,!c,col);
                if(!ans)
                return 0;
            }
            else if(col[it]==int(c))
            return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()+1,-1);
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                bool ans=help(graph,i,0,color);
                if(!ans)
                return 0;
            }
        }
        return 1;
    }
};
