class Solution {
public:
    int maxPower(string s) {
        
        char curr = s[0];
        int ans = 0;
        int temp = 0;
    
        for(int i= 0 ; i< s.length() ; i++){
            if(curr == s[i]){
                temp++;
            }
            else {
                ans = max(temp , ans);
                temp = 1;
                curr = s[i];
                
            }
        }
        return max(ans, temp);
    }
};