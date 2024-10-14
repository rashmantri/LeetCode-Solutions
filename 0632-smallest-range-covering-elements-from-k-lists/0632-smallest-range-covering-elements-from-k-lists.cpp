#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(); // number of lists
        vector<int>resRange = {-100000, 100000}; // store the result range
        int maxe = INT_MIN; // to track the maximum element in the current window
        
        // Min-heap to store the current element from each list, along with its list index and element index
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        // Initialize the heap and find the initial max element
        for(int i = 0; i < k; i++) {
            int element = nums[i][0];
            minHeap.push({element, {i, 0}});
            maxe = max(maxe, element);
        }
        
        while(true) {
            // Get the smallest element (min element) from the heap
            auto [minElement, idxPair] = minHeap.top();
            minHeap.pop();
            
            int listIdx = idxPair.first;
            int elIdx = idxPair.second;
            
            // Update the result range if the current range is smaller
            if(maxe - minElement < resRange[1] - resRange[0]) {
                resRange = {minElement, maxe};
            }
            
            // Move the pointer to the next element in the list that had the min element
            if(elIdx + 1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][elIdx + 1];
                minHeap.push({nextElement, {listIdx, elIdx + 1}});
                maxe = max(maxe, nextElement); // update the max element
            } else {
                // If we've exhausted one of the lists, we can't form a valid range anymore
                break;
            }
        }
        
        return resRange;
    }
};
