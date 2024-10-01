class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;

        for(auto it:arr){
            // cout<<it%k<<endl;
            if(it%k<0)
                mp[it%k+k]++;
            else
                mp[it%k]++;
        }

        bool ans = true;

        for(int i=0;i<k;i++){
            cout<<i<<" "<<mp[i]<<endl;
            if(i==0){
                if(mp[i]%2!=0){
                    
                    ans=false;
                    break;
                }
            }
            else if(mp[i] != mp[k-i]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};