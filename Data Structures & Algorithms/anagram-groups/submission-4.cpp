class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(int j=0; j<strs.size(); j++){
            vector<int> count(26, 0);

            for(int i=0; i<strs[j].size(); ++i){
                count[strs[j][i]-'a']++;
            }

            string key = to_string(count[0]);
            for(int i=1; i<26; ++i){
                key+= "," + to_string(count[i]);
            }

            m[key].push_back(strs[j]);
        }

        vector<vector<string>> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }

        return ans;
    }
};
