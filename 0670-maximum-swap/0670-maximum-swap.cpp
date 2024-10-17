class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n=s.length();
        priority_queue<int>pq;
        
        for(int i=0;i<s.length();i++){
            pq.push(s[i]-'0');
        }
       
        int idx;
        for(idx=0;idx<n;idx++){
            if(pq.top()==s[idx]-'0'){
                pq.pop();
            }
            else{
                break;
            }
        }
        int maxn = s[idx]-'a';
        int maxIdx = idx;
        for(int i=idx;i<n;i++){
            if(s[i]-'0'>=maxn){
                maxn = s[i]-'0';
                maxIdx = i;
            }
        }

        char temp = s[idx];
        s[idx] = s[maxIdx];
        s[maxIdx] = temp;

        return stoi(s);
    }
};