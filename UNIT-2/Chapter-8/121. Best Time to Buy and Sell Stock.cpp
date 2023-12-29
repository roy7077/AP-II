// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==0 or prices.size()==1)
        return 0;
        
        int min=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-min>profit)
                profit=prices[i]-min;
            
            if(prices[i]<min)
                min=prices[i];
        }
        return profit;
    }
};