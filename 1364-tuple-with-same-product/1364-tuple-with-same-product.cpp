class Solution {
public:

long nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

long fact(int n)
{
      if(n==0)
      return 1;
    long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
    int tupleSameProduct(vector<int>& nums) {
        
        int count=0;
        unordered_map<int, int> mp;
        for(int i=0; i< nums.size() ; i++){
                for(int j=i+1 ;j< nums.size() ; j++){

                       int product = nums[i] * nums[j];
                count += 8 * mp[product];
                mp[product]++;
                }
        }

        // for(auto i : mp){
        //     cout<< i.first<<","<<i.second<<endl;
        //     if(i.second !=1) {
        //         cout<<"count= "<< (nCr(i.second , 2) * pow(2, i.second))<<endl;
        //         count+=((i.second ==2 ? 2 : nCr(i.second , 2)) * pow(2, i.second));

        //     }
        // }

        return count;
    }
};