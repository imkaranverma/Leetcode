class Solution {
public:
    bool checkValidString(string s) {
        // NOTE - in the starting of ques I thought of using
        // 2 stacks 1 for only storing ( and 1 for * and jaise
        // hi hme ) milega usko hmm cancel out kra denge as a
        // valid pair but first we will try with ( and then *
        // kyuki star ko initially use kyu hi kre jab hmare pass
        // ( bracket ha.
        // GOOD APPROACH
        stack<int> st;
        stack<int> star;
        int i;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                // we are pushing indexes of brackets
                st.push(i);
            } else if(s[i]=='*')
            {
                // we are pushing indexes of brackets
                star.push(i);
            } else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                } else if(!star.empty())
                {
                    star.pop();
                } else
                {
                    // agar ) cancel out krane ke liye hmare pass ek
                    // bhi  ( ya * nhi ha toh return false.
                    return false;
                } 
            }
        }
        // if any one stack becomes empty condn breaks
        while(!star.empty() && !st.empty())
        {
            // *( -> if open brack comes later then we can't
            // balance it.
            if(st.top()>star.top())
            {
                return false;
            }
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};