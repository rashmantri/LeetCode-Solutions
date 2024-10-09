class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(auto ch:s){
            if(ch=='('){
                st.push(ch);

            }
            else if(st.size()){
                st.pop();
            }
            else{
                cnt++;
            }
        }

        return cnt+st.size();
    }
};