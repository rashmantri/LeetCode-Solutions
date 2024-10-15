class Solution {
public:
    long long minimumSteps(string s) {
        
        int n = s.length(),idxOfLastOne = n-1;
        long long cnt=0;

        for(int i = n-1;i>=0;i--){
            if(s[i]=='1'){
                cnt+= idxOfLastOne - i;
                idxOfLastOne--;
            }
        }
        return cnt;
    }
};