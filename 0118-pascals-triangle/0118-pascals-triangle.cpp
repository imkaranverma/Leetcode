class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int i=1; i<=numRows ; i++){
            vector<int> temp;
            for(int j=0; j<i; j++){
                // cout<< "i="<<i<<"j="<<j<<endl;
                // cout<<ans;
                if(j==0){
                    temp.push_back(1);
                }
                else if(j==i-1) {
                        temp.push_back(1);
                }
                else {
                    temp.push_back(ans[i-2][j-1] + ans[i-2][j]);
                }
            }
            // for(int x=0; x<temp.size(); x++)
            // cout<<"temp="<<temp[x]<<endl;
            ans.push_back(temp);
        }
        return ans;
    }
};
