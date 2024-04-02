class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        

        unordered_map<double , int> ratioo;
        long long ans = 0;

            for(int i=0 ; i< rectangles.size(); i++){
                double temp = rectangles[i][0]/double(rectangles[i][1]);
                ans+= ratioo[temp];
                ratioo[temp]++;
            }

        return ans;

    }
};