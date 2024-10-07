class Solution {
public:
    int minLength(string s) {
        int n=s.length();
        int num=n;
        link:
        for(int i=0;i<num-1;i++){
            if((s[i]=='A' && s[i+1]=='B')||(s[i]=='C' && s[i+1]=='D'))
            {
                s.erase(i, 2);
                num=num-2;
            }
        }
        if(num!=n){
            n=num;
            goto link;
        }
        return num;
    }
};