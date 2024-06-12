class Solution {
public:
    void sortColors(vector<int>& nums) {

        // 0 - (Low-1) : RED
        // low - (mid-1): WHITE
        // mid - high-1 : unsorted
        // high - (n-1) : BLUE
        
        int low=0, mid=0, high = nums.size()-1;
       while(mid <= high){
        //    cout<< mid<< endl;
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++, mid++;
                // cout<< "1st"<<endl;
            }

            else if(nums[mid] == 1) {
                mid++;
                // cout<< "2nd"<<endl;

            }

            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
                // cout<< "3rd"<<endl;
            }
        }

    }
};