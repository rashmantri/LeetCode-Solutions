class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int s = skill[0] + skill[n-1];
        long long ans=0;
        for(int i=0;i<n/2;i++){
            if(skill[i]+skill[n-i-1]==s){
                ans+=1LL*skill[i]*skill[n-i-1];
            }
            else{
                return -1;
            }
        }
        return ans;
        
    }
};