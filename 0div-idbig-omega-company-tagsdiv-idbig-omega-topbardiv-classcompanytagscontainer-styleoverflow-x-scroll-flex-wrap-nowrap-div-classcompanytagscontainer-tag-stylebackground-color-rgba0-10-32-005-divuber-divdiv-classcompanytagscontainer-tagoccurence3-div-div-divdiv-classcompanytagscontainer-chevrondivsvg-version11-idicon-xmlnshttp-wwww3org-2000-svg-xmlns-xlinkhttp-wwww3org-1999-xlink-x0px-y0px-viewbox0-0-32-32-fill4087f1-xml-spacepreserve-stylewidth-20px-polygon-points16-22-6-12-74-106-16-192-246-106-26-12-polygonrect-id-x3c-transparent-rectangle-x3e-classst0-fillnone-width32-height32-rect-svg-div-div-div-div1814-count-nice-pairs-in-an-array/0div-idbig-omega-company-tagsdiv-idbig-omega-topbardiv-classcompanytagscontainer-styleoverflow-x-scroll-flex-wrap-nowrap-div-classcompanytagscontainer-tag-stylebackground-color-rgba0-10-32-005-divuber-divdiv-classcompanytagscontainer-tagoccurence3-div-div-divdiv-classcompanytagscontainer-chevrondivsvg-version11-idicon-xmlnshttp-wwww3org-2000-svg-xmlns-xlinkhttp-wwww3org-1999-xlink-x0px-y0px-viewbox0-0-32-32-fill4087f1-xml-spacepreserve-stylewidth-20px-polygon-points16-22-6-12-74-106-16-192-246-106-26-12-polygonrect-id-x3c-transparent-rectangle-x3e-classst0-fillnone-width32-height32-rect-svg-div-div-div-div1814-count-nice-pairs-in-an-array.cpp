class Solution {
public:

    int rev(int x){
        int ans = 0;
        int n = x;

        while(n){
            ans = (ans*10) + (n%10);
            n = n/10;
        }

        return ans;
    }
    int countNicePairs(vector<int>& nums) {

        // int m =  1000000007;
        // vector<int> diff;
        unordered_map <int , int> difff;
        int ans = 0;

        for(int i=0; i< nums.size() ;i++){
                int temp = (nums[i] - rev(nums[i]));
                // ans = ans %1000000007;
                ans= (ans + (difff[temp]))%1000000007;
                difff[temp]++;
        }

        return ans %1000000007;

    }
};