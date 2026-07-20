class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the input array
        sort(nums.begin(), nums.end());
        
        // Step 2: Iterate through the array to fix the first element
        for (int i = 0; i < n - 2; i++) {
            // Optimization: If the fixed element is positive, three positives can never sum to zero
            if (nums[i] > 0) break; 
            
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Step 3: Initialize Two Pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a larger value
                } 
                else {
                    right--; // Need a smaller value
                }
            }
        }
        return result;
    }
};
