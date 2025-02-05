class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count =0;
        string temp1= "";
        string temp2= "";

        for(int i=0; i<s1.length() ; i++){
            if(s1[i]!=s2[i]){
            count++;
            temp1+= s1[i];
            temp2+= s2[i];
            } 
        }

        if(temp1.size() > 2) return false;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
         
        return (temp1 == temp2 ? true : false);
    }
};