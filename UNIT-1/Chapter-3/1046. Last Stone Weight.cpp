// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution {
    public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(auto it:stones)
        pq.push(it);
        
        while(pq.size()>1)
        {
            int max1=pq.top();
            pq.pop();
            int max2=pq.top();
            pq.pop();
            
            if(max1!=max2)
            pq.push(max1-max2);
        }
        
        return pq.empty()? 0:pq.top();
    }
};
