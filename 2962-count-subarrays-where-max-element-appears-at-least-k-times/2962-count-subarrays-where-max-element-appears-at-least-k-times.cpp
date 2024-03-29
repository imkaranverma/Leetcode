class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = 0;
        int maxiFreq =0;
        
        int i =0, j=0;
        
        long long ans =0;
        int n = nums.size();
        
        for(int i= 0 ; i< n ; i++){
            maxi = max(maxi , nums[i]);
        }
        
        while(j< n){
            
            // cout<< " i= "<< i << " j ="<< j;
            if(nums[j] == maxi)  maxiFreq++;
            
            
//             if(maxiFreq == k){
                
//             // cout<< " . "<< n-j;
//             }
            
            while(maxiFreq>= k){
                ans+= (n - j);
                if(nums[i] == maxi) maxiFreq--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};