class Solution {
public:
    string makeGood(string s) {
        
        
        stack<char> st;
        
        for(int i =0; i< s.length() ;i++){
            if(st.empty()){ 
                st.push(s[i]);
            continue;
            }
            
            
            if(abs(st.top() - s[i]) == 32){
            // while(st.top() - s[i]== ){
                st.pop();
            // }
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};