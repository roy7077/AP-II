// Time complexity - O(NlogN)
// Space complexity- O(N)
class KthLargest {
    public:
    priority_queue <int, vector<int>, greater<int>> pq;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto it:nums)
        {
            pq.push(it);
            if(pq.size()>k)
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size)
        pq.pop();
        
        return pq.top();
    }
};
