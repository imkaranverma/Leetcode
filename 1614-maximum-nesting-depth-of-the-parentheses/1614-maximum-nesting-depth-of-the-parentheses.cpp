class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int mx=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            st.push(s[i]);

            if(s[i]==')' && !st.empty())
            st.pop();

            int si=st.size();

            mx=max(mx,si);
        }

        return mx;
    }
};