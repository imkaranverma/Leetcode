class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum = 0;
        int minn = INT_MAX;
        int count = 0;

        int row = matrix.size();
        int col = matrix[0].size();

        for(int i =0 ; i< row ; i++){
            for(int j =0; j < col ; j++){
                if(matrix[i][j]<0) count++;

                minn = min(abs(matrix[i][j]) , minn);
                // cout<< " matrix: "<< abs(matrix[i][j]);
                sum+=abs(matrix[i][j]);
                // cout<< " sum: "<< sum;
            }
        }

// cout<< "minn : " << minn;
        return (count%2==1 ? sum - (2*minn) : sum);
    }
};