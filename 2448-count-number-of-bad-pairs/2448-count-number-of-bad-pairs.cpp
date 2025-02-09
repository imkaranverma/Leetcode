class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0;
        long long n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i< n ; i++){
                        int key = nums[i] - i;
                        count += mp[key];
                        mp[key]++;
        }
        return ((n*(n-1)/2) - count);
    }
};