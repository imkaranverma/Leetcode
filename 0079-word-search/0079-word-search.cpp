auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int m, int n, int row,
                int col) {
        if (word == "") {
            return true;
        }

        if (row < 0 || col < 0 || row >= m || col >= n ||
            board[row][col] != word[0]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = ' ';

        bool result = helper(board, word.substr(1), m, n, row - 1, col) ||
                      helper(board, word.substr(1), m, n, row + 1, col) ||
                      helper(board, word.substr(1), m, n, row, col - 1) ||
                      helper(board, word.substr(1), m, n, row, col + 1);

        board[row][col] = temp;

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        if (board.empty() || board[0].empty() || word.length() > m * n) {
            return false;
        }

        vector<int> f(256, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[board[i][j]]++;
            }
        }

        for (char c : word) {
            if (--f[c] < 0) {
                return false;
            }
        }

        if(f[word[0]] > f[word.back()]){
            reverse(word.begin(),word.end());
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && helper(board, word, m, n, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};






// class Solution {
// public:

// bool solve(vector<vector<char>>& board, int i , int j, string word , int x , vector<vector<int>> &dp){
    
//                     // cout<< " X="<< x<<" i ="<<i<< " j ="<<j<<endl;

//     if((x+1) > word.size()) return false;
//     if((x + 1)== word.size() && board[i][j] == word[x] && dp[i][j]==0) return true;

//     bool found = false;

//     // cout<< "working";
//     // right
//     if(j<(board[0].size()-1)  && (board[i][j+1] == word[x+1])  && dp[i][j+1]==0 ){
//         dp[i][j+1]--;
//             found = solve(board , i , j+1 , word , x+1 , dp);
//                     cout<< "1";
//         if(found) return true;
//     }
//     // cout<< "working";
//     // left
//     if(j>0 && (board[i][j-1] == word[x+1])  && dp[i][j-1]==0 ){
//          dp[i][j-1]--;
//             found = solve(board , i , j-1 , word , x+1 , dp);
//                     cout<< "2";
//         if(found) return true;
//     }
//     // cout<< "working";
//     // up
//     if(i>0  && (board[i-1][j] == word[x+1])  && dp[i-1][j]==0){
//        dp[i-1][j]--;
//         found = solve(board , i-1 , j , word , x+1 , dp);
//                     cout<< "3";

//         if(found) return true;
//     }


//     // cout<< "working";
//     // down
//     //     cout<< board.size()<<"|";
//     // cout<< board[i+1][j]<< ":"<< word[x+1];
//     if((i<(board.size() -1))  && (board[i+1][j] == word[x+1])  && dp[i+1][j]==0){
//           dp[i+1][j]--;
//             cout<< "4";
//             found = solve(board , i+1, j , word , x+1 , dp);
//         if(found) return true;
//     }

//         return found;

// }
//     bool exist(vector<vector<char>>& board, string word) {
        


//             unordered_map<char,int> freq;


//              for(int i = 0; i< board.size() ;i++){
//             for(int j =0; j< board[0].size() ;j++){
//                     // cout<< ",A ="<< board[i][j];
//                 freq[board[i][j]]++;
//             }
//         }

//             for(int i=0 ; i< word.size() ;  i++){
//                     // cout<< "B";
//                 freq[word[i]]--;

//                 if(freq[word[i]] < 0) return false;
//             }

//         // vector< vector<int>> dp(board.size() , 0);
//         vector<vector<int>>dp(board.size() , (board[0].size() , 0));
//         int  x =0;
//         bool found = false;
//         for(int i = 0; i< board.size() ;i++){
//             for(int j =0; j< board[0].size() ; j++){
//                     cout<< "O";
//                 if(board[i][j] == word[0]){
//                     found = solve(board ,i , j , word  , 0 , dp);
//                     if(found) return true;
//                 }
//             }
//         }

//         return false;
//     }
// };