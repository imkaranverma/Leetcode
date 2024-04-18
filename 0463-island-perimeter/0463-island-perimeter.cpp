class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;
        for(int i =0; i< row; i++){
            
            for(int j =0; j< col ; j++){
                
                if(grid[i][j] == 1){
                int land = 0;

//                 check left
                        if(j>0 && grid[i][j-1] == 1){
                                land++;
                        }

//                 check right
                         if(j<col-1 && grid[i][j+1] == 1){
                                land++;
                        }

//                 check down
                         if(i<row-1 && grid[i+1][j] == 1){
                                land++;
                        }
//                 check up
                         if(i>0 && grid[i-1][j] == 1){
                                land++;
                        }

                ans+= (4 - land);
                }
            }
        }

        return ans;
    }
};