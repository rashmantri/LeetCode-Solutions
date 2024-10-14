class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        long long s=0;
        for(int i=0;i<k;i++){
            int el = pq.top();
            s += el;
            pq.pop();
            pq.push(ceil(el/3.0));

 
        }
        return s;
    }
};