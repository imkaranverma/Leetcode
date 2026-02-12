class Solution {
public:
bool checkFreq(vector<int>& count){
    int temp = 0;
    for(int i =0; i< 26 ;i++){
        if(count[i] == 0 ) continue;
        if(temp == 0)
            temp = count[i];
        else if(temp != count[i]) return false;
    }
    return true;
}
    int longestBalanced(string s) {
        int n = s.length();
        int result = 0;

        for(int i=0; i< n ; i++){
        vector<int> count(26 , 0);
            for(int j=i; j< n ; j++){
               count[s[j] - 'a']++;
               if(checkFreq(count)){
                result = max(result , j - i + 1);
               } 
            }
        }
        return result;
    }
};