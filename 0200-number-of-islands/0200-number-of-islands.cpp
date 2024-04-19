class Solution {
public:
    void search(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &check){
        //to avoid invalid indices
        if(r < 0 || c < 0) return;
        if(r >= grid.size() || c >= grid[0].size()) return;
        
        //if 0 then stop and go back
        if(grid[r][c] == '0') return;
        
        //if already visited position then go back
        if(check[r][c] == 1) return;

        //current position is marked 
        //so as to avoid it in the future
        check[r][c] = 1;

        //checking in all 4 directions
        search(r-1, c, grid, check);
        search(r+1, c, grid, check);
        search(r, c+1, grid, check);
        search(r, c-1, grid, check);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> check(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]-'0' == 1 && check[i][j] != 1){
                    search(i, j, grid, check);
                    count++;
                }
            }
        }

        return count;
    }
};











// class Solution {
// public:

//     bool isNew(vector<vector<char>>& grid , int i , int j){
//          int row = grid.size();
//         int col = grid[0].size();

//         if(i>0 && grid[i-1][j] == '2') return false;
//         if(i<row-1 && grid[i+1][j] == '2') return false;
//         if(j>0 && grid[i][j-1] == '2') return false;
//         if(j<col-1 && grid[i][j+1] == '2') return false;

//             return true;
//     }
//     int numIslands(vector<vector<char>>& grid) {
        
//         int ans = 0;

//         int row = grid.size();
//         int col = grid[0].size();

//         for(int i= 0; i< row ; i++){
//             for(int j =0; j< col ;j++){
//                 if(grid[i][j] == '1' || grid[i][j] == '2'){ 
//                     if(isNew(grid , i , j)){
//                         // cout<<" i="<<i<<",j="<<j<<";";
//                         grid[i][j] = '2';
//                       ans++;
//                     }
//                       if(i>0 && grid[i-1][j] == '1') grid[i-1][j] = '2';
//                       if(i<row-1 && grid[i+1][j] == '1') grid[i+1][j] = '2';
//                       if(j>0 && grid[i][j-1] == '1') grid[i][j-1] = '2';
//                       if(j<col-1 && grid[i][j+1] == '1') grid[i][j+1] = '2';
//                     }
                
//                 // else {

//                 // }
                
//             }
//         }

//         // cout<< endl;

//         // // for()
//         // for(int i =0; i< row; i++){
//         //     for(int j = 0 ;j < col ; j++){
//         //         cout<<grid[i][j]<< " ";
//         //     }
//         //     cout<< endl;
//         // }

//         return ans;
//     }
// };