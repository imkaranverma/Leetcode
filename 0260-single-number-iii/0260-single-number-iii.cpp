class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int sum =0;
        // vector<int> ans(2 , 0);

        for(int i=0; i< nums.size() ; i++){
            sum = sum^nums[i];
        }

        int x =0 , y=0;
        int pow = 0;

        while(((sum>> pow) & 1) != 1){
            pow++;
        }

        for(int num : nums){
            if(((num >> pow) & 1) == 1) {
                x^= num;
            }
            else {
                y^= num;
            }
        }

        return {x , y};
    }
};