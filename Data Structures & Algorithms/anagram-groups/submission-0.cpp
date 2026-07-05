class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            // Convert count array into a unique string key
            string key;
            for (int x : count) {
                key += to_string(x) + '#';
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(group);
        }

        return res;
    }
};