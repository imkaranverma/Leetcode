class Solution {
public:

        int m , n;

            vector<vector<int>> direction = {{1 , 0} , {-1 , 0} , {0, 1} , {0, -1}};
        int DFS(vector<vector<int>>& grid,  int i , int j){
            // cout<< "working1 ";

                if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
                    // cout<< ";inside "<< i <<","<< j;
                    return 0;
                }

            // cout<< "working2 ";
            int ogValue = grid[i][j];
            grid[i][j] = 0;
            // cout<< "working3 ";

            int maxValue = 0;
                // cout<< "max : "<< maxValue;
                // cout<< "OG : "<< ogValue<< endl;

                for(auto& dirs: direction){
                    int new_i = i + dirs[0];
                    int new_j = j + dirs[1];

                    maxValue = max(maxValue , DFS(grid , new_i , new_j));
                }

                grid[i][j] = ogValue;

                // cout<< "max : "<< maxValue;
                // cout<< "OG : "<< ogValue<< endl;

                return maxValue + ogValue;
        }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        int maxValue = 0;

            for(int i =0; i< m ; i++){
                for(int j = 0; j< n ; j++){

                    if(grid[i][j]!= 0)
                    maxValue = max(maxValue, DFS(grid, i , j));

                }
            }

            return maxValue;
    }
};