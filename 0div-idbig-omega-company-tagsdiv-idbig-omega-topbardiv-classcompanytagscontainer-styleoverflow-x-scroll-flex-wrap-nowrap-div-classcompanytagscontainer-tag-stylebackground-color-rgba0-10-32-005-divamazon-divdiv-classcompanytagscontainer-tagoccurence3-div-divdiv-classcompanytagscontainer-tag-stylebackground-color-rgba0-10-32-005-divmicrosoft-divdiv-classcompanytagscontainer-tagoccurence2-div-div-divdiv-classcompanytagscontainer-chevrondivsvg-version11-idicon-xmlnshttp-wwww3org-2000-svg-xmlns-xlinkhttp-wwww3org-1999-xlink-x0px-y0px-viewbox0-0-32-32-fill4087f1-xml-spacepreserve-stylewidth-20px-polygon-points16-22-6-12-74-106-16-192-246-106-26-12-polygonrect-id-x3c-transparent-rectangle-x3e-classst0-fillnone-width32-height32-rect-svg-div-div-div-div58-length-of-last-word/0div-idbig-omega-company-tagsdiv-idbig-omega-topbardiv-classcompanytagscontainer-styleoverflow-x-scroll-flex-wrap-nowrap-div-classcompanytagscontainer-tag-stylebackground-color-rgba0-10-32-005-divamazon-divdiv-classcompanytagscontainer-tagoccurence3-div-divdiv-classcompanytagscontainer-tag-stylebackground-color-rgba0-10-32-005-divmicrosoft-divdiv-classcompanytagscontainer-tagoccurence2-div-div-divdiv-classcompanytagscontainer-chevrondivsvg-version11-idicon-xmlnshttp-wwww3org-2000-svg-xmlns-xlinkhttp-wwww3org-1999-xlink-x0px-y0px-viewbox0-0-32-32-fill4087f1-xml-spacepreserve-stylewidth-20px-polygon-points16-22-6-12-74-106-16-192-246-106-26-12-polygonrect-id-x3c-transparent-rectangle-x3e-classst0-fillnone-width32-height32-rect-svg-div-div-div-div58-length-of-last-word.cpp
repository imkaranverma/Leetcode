class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length();
        bool found = false;
        int ans = 0;
        
        for(int  i= n-1 ; i>=0 ; i--){
            if(found){
                if(s[i] != 32) ans++;
                else return ans;
            }else {
                if(s[i] != 32){
                    found = true;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};