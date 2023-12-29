/*---------------Method-1------------*/
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int a=nums[i];
                int b=nums[j];
                int c=nums[k];
                
                if((a+b+c)==0)
                {
                    st.insert({a,b,c});
                    j++;
                    k--;
                }
                else if((a+b+c)>0)
                k--;
                else
                j++;
            }
        }
        
        for(auto it:st)
        ans.push_back(it);
        
        return ans;
        
    }
};


/*---------------Method-2------------*/
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int a=nums[i];
                int b=nums[j];
                int c=nums[k];
                
                if((a+b+c)==0)
                {
                    ans.push_back({a,b,c});
                    
                    while(j<n and nums[j]==b)
                    j++;
                
                    while(k>=0 and nums[k]==c)
                    k--;
                }
                else if((a+b+c)>0)
                k--;
                else
                j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) 
            i++;
        }
        return ans;
        
    }
};