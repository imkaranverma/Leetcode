class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int result =0;
        for(int i=0; i<n; i++){
            set<int> even;
            set<int> odd;

            for(int j=i; j<n; j++){
                    if(nums[j] %2 ==0){
                        even.insert(nums[j]);
                    }
                    else odd.insert(nums[j]);
                
                if(even.size() == odd.size()){
                    result = max(result , j-i+1);
                }
            }
        }
        return result;
    }
};