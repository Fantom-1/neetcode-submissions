class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Use a min-heap to keep the top k elements
        // Pair structure: {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& pair : counts) {
            minHeap.push({pair.second, pair.first});
            // Keep heap size exactly k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract the k elements from the heap into the answer vector
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
