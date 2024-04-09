class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int n=t.size();
        int ans=0;
        
              while(t[k]!=0){
                for(int i=0;i<n;i++){
                    if(t[i]>0){
                        t[i]-=1;
                        ans++;
                    }
                    if(i==k && t[i]==0){
                        return ans;
                        break;
                    }
                }
              }
              return 0;
    }
};