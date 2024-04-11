class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 1;
        stack<char> st;
        st.push(num[0]);
        while(i<num.size()){
            int curr = num[i];
            while(!st.empty() && st.top()>curr && k){
                st.pop();
                k--;
            }
            st.push(curr);
            i++;
        }
        string temp = "";
        while(k){
            st.pop();
            k--;
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        string res = "";
        i = 0;
        while(temp[i] == '0'){
            i++;
        }
        while(i<temp.size()){
            res+=temp[i];
            i++;
        }
        if(res == ""){
            return "0";
        }
        return res;
    }
};