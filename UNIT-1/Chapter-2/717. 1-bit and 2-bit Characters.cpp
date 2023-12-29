// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        while(i<n)
        {
            if(i==n-1)
            {
                if(bits[n-1])
                return 0;
                else
                return 1;
            }
            
            if(bits[i])
            i+=2;
            else
            i++;
        }
        
        return 0;
    }
};