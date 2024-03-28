class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        

        if(sx == fx && sy == fy && t== 1) return false;
        else if(sx == fx && sy == fy && t!= 1) return true;
        int maxi = max(abs(fx - sx) , abs(fy - sy));

        return (maxi <= t);
    }
};