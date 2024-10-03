class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
     
        int curr=0,target=0;
        for(auto it:nums){
            target=(target+it)%p;
        }
        
        target=target%p;

        if(target==0) return 0;
        unordered_map<int,int>mp;//{sum%p , value}
        mp[0]=-1;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            curr=(curr + nums[i])%p;

            if(mp.find((curr-target+p)%p)!=mp.end()){
                ans = min(ans , i - mp[(curr-target+p)%p]);
            }

            mp[curr]=i;


        }
        if(ans==n) return -1;
        return ans;



    
        


    }
};