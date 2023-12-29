// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int size=fb.size();
        if(size==1)
        {
            if(n==0)
            return 1;
            
            if(fb[0]==0)
            return 1;
            else
            return 0;
        }
        
        int i=0;
        while(i<size)
        {
            if(n==0)
            break;
            
            if(i==0)
            {
                if(fb[i]==0 and fb[i+1]==0)
                {
                    fb[i]=1;
                    n--;
                    i+=2;
                }
                else
                i++;
            }
            else if(i==size-1)
            {
                if(fb[i]==0 and fb[i-1]==0)
                {
                    fb[i]=1;
                    n--;
                    i+=2;
                }
                else
                i++;
            }
            else
            {
                if(i-1>=0 and i+1<size and fb[i]==0 and fb[i-1]==0 and fb[i+1]==0)
                n--,i+=2;
                else
                i++;
            }
        }
        
        if(n==0)
        return 1;
        else
        return 0;
    }
};