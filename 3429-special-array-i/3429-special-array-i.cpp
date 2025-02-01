class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        bool odd = nums[0]%2== 0 ? false : true;

        for(int i=1; i<nums.size() ; i++){
            if((odd && nums[i]%2!=0 )|| (!odd && nums[i]%2==0))
            return false;

            else {
                odd = !odd;
            }
        }
        return true;
    }
};