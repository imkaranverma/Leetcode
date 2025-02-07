class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball;
        unordered_map<int, int> color;
        vector<int> ans;
        int count =0;
        for(int i=0; i< queries.size(); i++){
            
                if(ball[queries[i][0]] ==0 && color[queries[i][1]]==0){
                        count++;
                        ans.push_back(count);
                        ball[queries[i][0]]=queries[i][1];
                         color[queries[i][1]]++;
                }
                else {
                    if(ball[queries[i][0]] !=0){
                        color[ball[queries[i][0]]]--;
                        cout<< "i= "<< i<<",";
                    // cout<<"color[ball[queries[i][0]]]: "<<color[ball[queries[i][0]]]<<",";
                        if(color[ball[queries[i][0]]]==0) count--;
                        
                        color[queries[i][1]]++;
                    //   cout<< "color[queries[i][1]]: "<< color[queries[i][1]]<<endl;
                        if(color[queries[i][1]] ==1) count++;

                          ball[queries[i][0]]=queries[i][1];
                        ans.push_back(count);
                    }
                    else {
                        color[queries[i][1]]++;
                        ball[queries[i][0]]=queries[i][1];
                        ans.push_back(count);
                    }
                }
        }
    return ans;
    }
};