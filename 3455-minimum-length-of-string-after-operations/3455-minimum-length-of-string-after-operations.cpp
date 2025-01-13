class Solution {
public:
    int minimumLength(string s) {
        
        unordered_map <int, int> mp;
        int ans = 0;

        for(int i=0; i< s.length() ; i++){
            mp[s[i]]++;
        }

           for (auto i : mp) {
                if(i.second % 2 == 0) ans+=2;

                else ans+=1;
        }
    // cout<< "ANS:" << ans;
        return ans;
    }
};