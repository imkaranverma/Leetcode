class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int count = 0;
        for(int i=s.length()-1; i>=0 ; i--){
            cout<<"s[i]:"<< s[i];
            if(s[i]>=48 && s[i]<=57){
                count++;
                continue;
            }
            if(count!=0){
                count--;
                continue;
            }
            else {
                ans = s[i] + ans;
            }
            
        }
        return ans;
    }
};