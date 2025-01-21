class Solution {
public:
    void nextPermutation(vector<int>& v) {
    int n=v.size();
    int pivotIdx=-1;
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            pivotIdx=i;
            break;
        }
    }
    if(pivotIdx==-1){
        reverse(v.begin(),v.end());
        return;
    }
    reverse(v.begin()+pivotIdx+1,v.end());

    int j=-1;
    for(int k=pivotIdx+1;k<n;k++){
        if(v[k]>v[pivotIdx]){
          j=k;
          break;
        }
    }
    //swap
    int temp=v[j];
    v[j]=v[pivotIdx];
    v[pivotIdx]=temp;
    }
};