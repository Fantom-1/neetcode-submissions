class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int j = 1;
        while(j<n){
            for(int i=0;i<j;i++){
            if(numbers[i]+numbers[j]==target) return {i+1, j+1};
            }
            j++;
        }
    }
};
