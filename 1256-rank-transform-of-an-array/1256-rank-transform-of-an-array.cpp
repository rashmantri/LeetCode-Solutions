class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n=arr.size();
        if(n==0) return {};
        vector<pair<pair<int,int>,int>>vec;
        vector<int>res;
        
        for(int i=0;i<n;i++){
            vec.push_back({{arr[i],arr[i]},i});
        }
        sort(vec.begin(),vec.end());
        int x=1;
        vec[0].first.second = 1;
        for(int i=1;i<n;i++){
            if(vec[i].first.first == vec[i-1].first.first){
                 vec[i].first.second=x;
            }
            else{
                vec[i].first.second=++x;
            }
        }

        sort(vec.begin(),vec.end(),[](pair<pair<int,int>,int>&a , pair<pair<int,int>,int>&b){
            return a.second<b.second;
        });
        
        for(auto it:vec){
            res.push_back(it.first.second);
        }

        return res;

    }
};