class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                total += n - j;
                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }
            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }
            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return res;
    }
};











// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        

//         vector<pair<int , pair<int, int>>> temp;

//         int n = arr.size();

//         for(int i =0; i< n ; i++){
//                 for(int j = i+1 ; j< n ; j++){

//                     pair<int , pair<int, int>> sam;
//                     sam.second.first = arr[i];
//                     sam.second.second = arr[j];
//                     sam.first = (arr[i]/arr[j]);
//                 }
//         }

//         sort(arr.begin() , arr.end());

//         vector<int> ans;
//         ans.push_back(ans[k-1].second.first);
//         ans.push_back(ans[k-1].second.second);
//         //  {ans[k-1].second.first , arr[k-1].second.second};

//         return ans;
//     }
// };