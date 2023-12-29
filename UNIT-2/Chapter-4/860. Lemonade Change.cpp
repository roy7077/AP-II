/*----------------Method-1--------------*/
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(auto it:bills)
        {
            if(it==5)
            mp[5]++;
            else if(it==10)
            {
                if(mp[5]==0)
                return 0;
                else
                {
                    mp[10]++;
                    mp[5]--;
                }
            }
            else
            {
                if(mp[5]>=1 and mp[10]>=1)
                {
                    mp[5]--;
                    mp[10]--;
                    mp[20]++;
                }
                else if(mp[5]>=3)
                {
                    mp[5]-=3;
                    mp[20]++;
                }
                else
                return 0;
            }
        }
        return 1;
    }
};


/*----------------Method-2--------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool lemonadeChange(vector<int> bills) {
    int f=0;
    int t=0;
    for (int it:bills) {
        if(it==5)
        f++;
        else if(it==10)
        {
            f--;
            t++;
        }
        else if(t>0)
        {
            t--;
            f--;
        }
        else 
        f-=3;
        
        if(f<0)
        return false;
    }
    return true;
 }
};
