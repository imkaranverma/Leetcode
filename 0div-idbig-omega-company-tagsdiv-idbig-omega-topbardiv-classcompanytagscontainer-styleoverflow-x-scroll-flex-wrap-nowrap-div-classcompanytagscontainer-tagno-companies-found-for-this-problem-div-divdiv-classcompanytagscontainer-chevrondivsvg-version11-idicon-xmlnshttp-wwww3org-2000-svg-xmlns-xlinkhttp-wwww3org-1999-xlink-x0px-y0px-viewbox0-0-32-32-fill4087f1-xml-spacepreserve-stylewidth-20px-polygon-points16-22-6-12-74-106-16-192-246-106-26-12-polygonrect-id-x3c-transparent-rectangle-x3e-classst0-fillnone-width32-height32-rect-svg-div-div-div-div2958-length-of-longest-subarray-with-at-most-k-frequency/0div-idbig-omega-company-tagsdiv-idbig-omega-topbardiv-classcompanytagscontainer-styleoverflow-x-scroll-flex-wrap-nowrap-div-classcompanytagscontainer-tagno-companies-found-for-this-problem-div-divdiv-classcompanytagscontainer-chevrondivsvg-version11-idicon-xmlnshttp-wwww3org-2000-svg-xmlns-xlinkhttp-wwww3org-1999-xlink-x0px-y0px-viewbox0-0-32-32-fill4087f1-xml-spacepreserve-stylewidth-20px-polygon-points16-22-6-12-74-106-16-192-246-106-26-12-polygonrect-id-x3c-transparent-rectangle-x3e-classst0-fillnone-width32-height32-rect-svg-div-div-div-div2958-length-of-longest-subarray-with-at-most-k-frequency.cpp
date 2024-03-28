class Solution {
public:
    
// //     bool check(unordered_map<int, int>& freq, int k){
// //          for(const auto &pair : freq) {
// //        if(pair.second > k) return false;
// //          }
        
// //         return true;
// //     }
    
//     int maxSubarrayLength(vector<int>& nums, int k) {
        
//     //     unordered_map<int, int> freq;
//     //     bool isvalid= true;
//     //     int first =0, sec=0;
        
//     //     for(int i=0; i<nums.size() ; i++){
//     //         // cout<< endl;
//     //         // cout<< " first : "<< first;
//     //         // cout<< " sec : "<< sec<<endl;
            
//     //       if(freq[nums[i]] < k){
//     //           // cout<< " s1 ";
//     //           freq[nums[i]]++;
//     //           sec++;
//     //       }
            
            
//     //        else {
               
//     //            if(nums[i] == nums[sec]){
//     //                continue;
//     //            }
               
              
//     //             // cout<< " s2 ";
//     //            while(nums[first] != nums[i]){
//     //                first++;
//     //            }
               
//     //            first++;
//     //            sec++;
//     //            continue;
//     //         }
            
            
//     //        //  if(freq[nums[i]] > k) isvalid = false;
//     //     }
        
//     //     return (sec - first);
        
        
//     // }
// };


int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> ump;
    int ans = 0, i = 0, j = 0;
    while(j < nums.size()){
        ump[nums[j]]++;
        while(i <= j && ump[nums[j]] > k){
            ump[nums[i]]--;  i++;
        }
        j++;
        ans = max(ans, j - i);
    }
    return ans;
}
};