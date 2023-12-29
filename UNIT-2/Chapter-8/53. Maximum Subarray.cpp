/*------------Kadane's algorithm------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=-1e9;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
};