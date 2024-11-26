class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minn = INT_MAX;
        int ans = 0;

        for(int i=0; i<prices.size(); i++){
            minn = min(minn , prices[i]);

            if(prices[i] > minn){
                // cout<< "minn: "<< minn << "prices[i]: "<< prices[i] <<" ans: "<< ans <<endl;
                ans =max(ans,  prices[i] - minn);
            }
        }

        return ans;
    }
};