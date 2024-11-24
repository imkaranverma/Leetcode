class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        vector<int> n(nums.size() , 3);
        int low = 0;
        int mid= 1;
        int high= nums.size() -1;

        for(int i= 0 ;i< nums.size(); i++){
            if(nums[i] == 0){
                n[low] = 0;
                low++;
                // mid++;
            }
            else if(nums[i] == 2){
                 n[high] = 2;
                 high--;
            }
        }

        for(int i=low; i<=high ;i++){
            n[i]=1;
        }

        for(int i = 0; i< n.size() ; i++){
            nums[i] = n[i];
        }
    }
};