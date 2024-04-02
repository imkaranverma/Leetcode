class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        map<char,vector<int>>v1,v2;
        for(int i=0;i<s.size();i++){
            if(v1[s[i]].size()==0 || v1[s[i]].back()!=t[i])
            v1[s[i]].push_back(t[i]);

            if(v2[t[i]].size()==0 || v2[t[i]].back()!=s[i])
            v2[t[i]].push_back(s[i]);
        }

        for(int i=0;i<s.size();i++){
            if(v1[s[i]].size()!=1 ||  v2[t[i]].size()!=1){
                return false;
            }
        }
        return true;
    
    }
};