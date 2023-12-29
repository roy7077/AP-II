/*--------------Method-1-----------------*/
//BFS
class Solution {
    public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        
        int cap=jug1+jug2;
        int arr[]={jug1,-jug1,jug2,-jug2};
        unordered_map<int,bool> mp;
        queue<int> q;
        q.push(0);
        mp[0]=1;
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            
            if(n==target)
            return 1;
            
            for(int i=0;i<3;i++)
            {
                int temp=n+arr[i];
                
                if(temp>=0 and temp<=cap and !mp.count(temp))
                {
                    mp[temp]=1;
                    q.push(temp);
                }
            }
        }
        
        return 0;
    }
};


/*--------------Method-2-----------------*/
//DFS
class Solution {
    public:
    bool dfs(int node,int* arr,unordered_map<int,bool>& mp,int& cap,int& target)
    {
        if(node==target)
        return 1;
        
        mp[node]=1;
        for(int i=0;i<3;i++)
        {
            int temp=node+arr[i];
            if(temp>=0 and temp<=cap and !mp.count(temp))
            {
                bool ans=dfs(temp,arr,mp,cap,target);
                if(ans)
                return 1;
            }
        }
        return 0;
    }
    bool canMeasureWater(int jug1, int jug2, int target) {
        
        int cap=jug1+jug2;
        int arr[]={jug1,-jug1,jug2,-jug2};
        unordered_map<int,bool> mp;
        
        return dfs(0,arr,mp,cap,target);
    }
};