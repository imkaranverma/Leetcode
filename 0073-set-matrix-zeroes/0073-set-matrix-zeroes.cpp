class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col= matrix[0].size();
        int row = matrix.size();
        vector<int> temp_row;
        vector<int> temp_col;
        

        for(int i=0; i< row; i++){
            for(int j=0 ; j< col ; j++){
                    if(matrix[i][j] == 0){
                        temp_row.push_back(i);
                        temp_col.push_back(j);
                    }
            }
        }
 for(int i=0 ; i< temp_row.size(); i++){
     for(int j=0 ; j< col; j++)  matrix[temp_row[i]][j]=0;
 }

 
 for(int i=0 ; i< temp_col.size(); i++){
     for(int j=0 ; j< row; j++)  matrix[j][temp_col[i]]=0;

 }

    }
};