class Solution {
    public:
    string removeDuplicateLetters(string s) {
        int last[26]={0};
        int used[26]={0};
        stack<char> st;

        for(int i=0;i<s.length();i++)
        last[s[i]-'a']=i;

        for(int i=0;i<s.length();i++)
        {
            char it=s[i];
            if(used[it-'a'])
            continue;

            if(st.empty())
            {
                st.push(it);
                used[it-'a']=1;
                continue;
            }

            while(!st.empty() and st.top()>it and last[st.top()-'a']>i)
            {
                used[st.top()-'a']=0;
                st.pop();
            }

            st.push(it);
            used[it-'a']=1;
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
