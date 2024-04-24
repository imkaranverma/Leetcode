class Solution {
public:
    int tribonacci(int n) {
        // int arr[38] = {0, 1, 1};
        if(n == 0) return 0;
        else if(n == 1 || n==2) return 1;

        int prev2 = 0;
        int prev = 1;
        int curr = 1;
        // else if(n == 2) return 1;
        for(int i=3; i<=n; i++) {
            // arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

            int temp = prev2 + prev + curr;
            prev2 = prev;
            prev= curr;
            curr = temp;
        }
        return curr;
    }
};


// class Solution {
// public:

// vector<int> dp;
//     int tribonacci(int n) {

//         dp.resize(n + 1, -1);

//         if(dp[n] != -1) return dp[n];

//             if(n == 0){
//               return  dp[0] = 0;
//             //  return 0;
//             }

//             else if(n == 1 || n == 2) return dp[1] = 1;

//             return dp[n] = (tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3));
       
//     }
// };