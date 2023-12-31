/*-------------Method-1--------------*/
// Time complexity - O(N/2)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> constructRectangle(int area) {
        vector<int> ans={-1,-1};
        int maxi=1e9;
        
        for(int i=area/2;i>=1;i--)
        {
            if(area%i==0)
            {
                int a=i;
                int b=area/i;
                
                if(a>=b and (a-b)<=maxi)
                {
                    maxi=a-b;
                    ans[0]=a;
                    ans[1]=b;
                }
            }
        }
        
        if(ans[0]==-1)
        return {area,1};
        
        return ans;
    }
};

/*-------------Method-2--------------*/
// Time complexity - O(sqrt(area))
// Space complexity- O(1)
class Solution {
    public:
    vector<int> constructRectangle(int area) {
        int n=sqrt(area);
        for(int i=n;i>=1;i--)
        {
            if (!(area%i))
            return {area/i,i};
        }
        
        return {-1,-1};
    }
};