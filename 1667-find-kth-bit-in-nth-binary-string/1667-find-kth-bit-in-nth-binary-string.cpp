class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s = "0";
        for(int i = 0;i<n;i++){
            string inverts = ""; 
            for(auto ch : s){
                if(ch == '1'){
                    inverts+='0';
                }
                else{
                    inverts+='1';
                }
            }
            reverse(inverts.begin(),inverts.end());
            s = s + '1' + inverts ;
        }

        return s[k-1];

    }
};