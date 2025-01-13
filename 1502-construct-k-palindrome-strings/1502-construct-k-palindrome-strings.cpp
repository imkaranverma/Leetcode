class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map <int, int> mp; 

            if(s.length() < k) return false;
        for(int i=0; i< s.length() ; i++){
            mp[s[i]]++;
        }

        int temp =  0;
        for(auto i: mp){
                if(i.second %2 ==1) {
                    temp++;
                }
        }

       return temp <= k ? true : false; 
    }
};