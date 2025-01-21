class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int max_sum = INT_MIN;

        for (int i=0 ;i< nums.size() ; i++){
            sum += nums[i];
            max_sum = max(sum , max_sum);
            if(sum < 0) {
                sum = 0;

            }
        }


    // if(max_sum == 0){
    //    int maxi_sum = INT_MIN;
    //     for(int i=0; i< nums.size() ; i++){
    //         // if(nums[i] == 0) return 0;

    //                 maxi_sum = max(maxi_sum , nums[i]);
    //     }

    //     return maxi_sum;
    // }

    return max_sum;

    }
};