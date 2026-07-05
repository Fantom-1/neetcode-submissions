class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     string res = "";
     int n =strs[0].size();
     for(int i=0;i<n;i++){
        for (string st : strs){
            if(i==st.size() || st[i] != strs[0][i]){
                return res;
            } 
            
        }
        res += strs[0][i];
     }
     return res;
    }
};
