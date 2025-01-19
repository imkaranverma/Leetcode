const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
class Solution {
public:
    static unsigned pack(unsigned h, unsigned i, unsigned j) {
        return (h << 16) | (i << 8) | j;
    }

    static array<int, 3> unpack(unsigned info) {
        array<int, 3> ans;
        ans[0] = info >> 16, ans[1] = (info >> 8) & 255, ans[2] = info & 255;
        return ans;
    }

    static int trapRainWater(vector<vector<int>>& height) {
        const int m = height.size(), n = height[0].size();
        if (m <= 2 || n <= 2)
            return 0; // No trapped water possible

        vector<unsigned> boundary(2 * (m + n - 1));

        // Add boundary cells  mark  visited
        int idx = 0;
        for (int i = 0; i < m; i++) {
            boundary[idx++] = pack(height[i][0], i, 0);
            boundary[idx++] = pack(height[i][n - 1], i, n - 1);
            height[i][0] = height[i][n - 1] = -1; // visited
        }

        for (int j = 1; j < n - 1; j++) {
            boundary[idx++] = pack(height[0][j], 0, j);
            boundary[idx++]=pack(height[m - 1][j], m - 1, j);
            height[0][j] = height[m - 1][j] = -1; // visited
        }

        // Build a min-heap
        make_heap(boundary.begin(), boundary.end(), greater<>());

        int ans = 0, water_level = 0;

        while (!boundary.empty()) {
            // Extract the smallest element from the heap
            pop_heap(boundary.begin(), boundary.end(), greater<>());
            unsigned info = boundary.back();
            boundary.pop_back();

            auto [h, i, j] = unpack(info);
            water_level = max(water_level, h);

            // Process adjacent cell
            for (int k = 0; k < 4; k++) {
                int i0 = i + di[k], j0 = j + dj[k];
                if (i0 < 0 || i0 >= m || j0 < 0 || j0 >= n ||
                    height[i0][j0] == -1)
                    continue;

                int currH = height[i0][j0];
                if (currH < water_level)
                    ans += water_level - currH;

                // Mark the cell as visited and push it to the heap
                height[i0][j0] = -1;
                boundary.push_back(pack(currH, i0, j0));
                push_heap(boundary.begin(), boundary.end(), greater<>());
            }
        }

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
        
//         // int start = (1,1);
//         // end= (m-1 , n-1);
//         int ans =0;
//         int row = heightMap[0].size();
//         // cout<< "row="<< row;
//         int col = heightMap.size();
//         // int MOD = 10000000000
//         // cout<< "col :" << col;

//         for(int i=1; i<col-1 ; i++){
//             for(int j=1; j<row-1; j++){

//             int left= (heightMap[i-1][j] > heightMap[i][j] ? heightMap[i-1][j] : INT_MAX);
//             int right= (heightMap[i+1][j] > heightMap[i][j] ? heightMap[i+1][j] : INT_MAX);
//             int top= (heightMap[i][j-1] > heightMap[i][j] ? heightMap[i][j-1] : INT_MAX);
//             int down= (heightMap[i][j+1] > heightMap[i][j] ? heightMap[i][j+1] : INT_MAX);
//             int MIN = min(min(min(left, right), top), down);

//             // int add = ;
//             cout<<"i="<< i<< "j="<< j<<endl;
//             cout<< "l="<< left<< ",r="<< right<< ",t=" << top << ",d="<< down<< ",min="<< MIN<<endl;
//             cout<< "ans+= "<< (MIN > heightMap[i][j] && MIN != INT_MAX ? abs(MIN - heightMap[i][j]) : 0)<<endl;
//             ans+= (MIN > heightMap[i][j] && MIN != INT_MAX ? abs(MIN - heightMap[i][j]) : 0);
//             }
//         }
//         return ans;
//     }
// };