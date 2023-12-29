/*-----------Method-1---------------------*/
//Using switch
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool isValid(string s) {
        bool flag=1;
        stack<char> st;
        for(auto it:s)
        {
            switch(it)
            {
                case '[':
                case '{':
                case '(': st.push(it);
                          break;
                case ']':
                          if(!st.empty() and st.top()=='[')
                          st.pop();
                          else
                          {
                              flag=0;
                              break;
                          }
                          break;
                
                case '}': 
                          if(!st.empty() and st.top()=='{')
                          st.pop();
                          else
                          {
                              flag=0;
                              break;
                          }
                          break;
                case ')':
                          if(!st.empty() and st.top()=='(')
                          st.pop();
                          else
                          {
                              flag=0;
                              break;
                          }  
                          break;
            }
            if(!flag)
            break;
        }
        
        if(st.size() or !flag)
        return 0;
        else
        return 1;
    }
};

/*-----------Method-2---------------------*/
//using if 
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    bool isValid(string s) {
        stack<char> st;
        bool flag=1;
        for(auto it:s)
        {
            if(it=='{' or it=='[' or it=='(')
            st.push(it);
            else
            {
                if(it==')')
                {
                    if(!st.empty() and st.top()=='(')
                    st.pop();
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                else if(it=='}')
                {
                    if(!st.empty() and st.top()=='{')
                    st.pop();
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                else
                {
                    if(!st.empty() and st.top()=='[')
                    st.pop();
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                
            }
            
            if(!flag)
            break;
        }
        
        if(st.size() or !flag)
        return 0;
        else
        return 1;
    }
};