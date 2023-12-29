/*----------------Method-1--------------*/
typedef pair<double,int> pi;
class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            priority_queue<pi> pq; 
            for(int i=0;i<points.size();i++)
            {
                auto it=points[i];
                double a=(it[0]-0)*(it[0]-0);
                double b=(it[1]-0)*(it[1]-0);
                double ans=sqrt(a+b);
                
                pq.push({ans,i});
                if(pq.size()>k)
                pq.pop();
            }
        
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            int ind=pq.top().second;
            pq.pop();
            ans.push_back({points[ind][0],points[ind][1]});
        }
        return ans;
    }
};


/*----------------Method-2-------------*/
//Time complexity - O(NlogN)
//Space complexity- O(1)
class Solution {
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
                return ((a[0]*a[0])+(a[1]*a[1])) < ((b[0]*b[0])+(b[1]*b[1]));
            });
        
        return vector<vector<int>> (points.begin(),points.begin()+k);
    }
};