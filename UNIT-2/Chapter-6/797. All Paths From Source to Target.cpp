//dfs
class Solution {
    public:
    void dfs_path(vector<vector<int>>& graph,vector<vector<int>> &ans,vector<int>& path,int curr )
    {
        path.push_back(curr);
        if(curr==graph.size()-1)
        {
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        
        for(auto x:graph[curr])
        dfs_path(graph,ans,path,x);
        
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
          vector<vector<int>> ans;
          vector<int> path;
        
         dfs_path(graph,ans,path,0);
        return ans;
    }
};

