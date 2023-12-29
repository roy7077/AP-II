lass Solution {
    public:
    static bool compHeight(vector<int> &v1, vector<int> &v2)
    {
        if(v1[0]==v2[0])
        return v1[1]<v2[1];
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(),people.end(),compHeight);
        vector<vector<int>> ans(n,vector<int> (2,-1));
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            int j=0;
            while(j<n)
            {
                if(count==people[i][1] and ans[j][0]==-1)
                break;
                else if(ans[j][0]>=people[i][0] or ans[j][0]==-1)
                count++;
                
                j++;
            }
            ans[j][0]=people[i][0];
            ans[j][1]=people[i][1];
        }
        return ans;
    }
};
