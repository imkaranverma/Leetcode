// class Solution {
// public:
//     int punishmentNumber(int n) {
//         vector<int> saved = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};

//         int ans =0;
//         //  int size = sizeof(saved) / sizeof(saved[0]); 
//         for(int i=0 ; i<=saved.size(); i++){
//             if(saved[i] <= n){
//                   ans+= (saved[i] * saved[i]);
//             }
//             else {
//                 break;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (canPartition(to_string(i * i), 0, i)) {
                sum += (i * i);
            }
        }
        return sum;
    }

    bool canPartition(string num, int index, int target) {
        if (index == num.length()) return target == 0;

        int sum = 0;
        for (int i = index; i < num.length(); i++) {
            sum = sum * 10 + (num[i] - '0');
            if (sum > target) break;
            if (canPartition(num, i + 1, target - sum)) return true;
        }
        return false;
    }
};
