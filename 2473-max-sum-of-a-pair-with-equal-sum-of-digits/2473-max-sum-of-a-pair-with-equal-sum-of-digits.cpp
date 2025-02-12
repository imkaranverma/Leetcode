class Solution {
public:
int sumOfDigit(int n){
    int ans = 0;
    int temp = n;
    while(temp >0){
        ans+= temp%10;
        temp= temp/10;
    }

    return ans;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
         int sum = 0;
        for(int i=0; i< nums.size() ; i++){
            int sod = sumOfDigit(nums[i]);

            if(mp[sod]==0) mp[sod] = nums[i];
            else {
                    sum = max(mp[sod] + nums[i] , sum);
                    mp[sod] = max(mp[sod] , nums[i]);
            }
        }
        return sum == 0 ? -1 : sum;
    }
};