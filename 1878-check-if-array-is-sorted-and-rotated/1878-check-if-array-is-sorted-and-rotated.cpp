class Solution {
public:
    bool check(vector<int>& nums) {
        
        bool flag = false;
        for(int i=0; i<nums.size()-1; i++){
                if(!flag){
                    if(nums[i]<=nums[i+1]){
                        continue;
                    }
                    else flag = !flag;
                }
                else {
                    if(nums[i]>nums[0] || nums[i] >nums[i+1]) return false;
                }
        }
        return (flag && nums[nums.size() -1] >nums[0] ? false : true);
    }
};