// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int cnt=0;
        for(auto it:s)
        {
            if(it=='(')
            st.push(it);
            else
            {
                if(st.empty())
                cnt++;
                else
                st.pop();
            }
        }
    
        cnt+=st.size();
        return cnt;
    }
};