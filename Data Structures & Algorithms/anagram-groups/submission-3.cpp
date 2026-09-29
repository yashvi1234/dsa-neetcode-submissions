class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(int i=0; i<strs.size(); ++i){
            vector<int> a(26, 0);
            string s = strs[i];
            for(int j=0; j<s.size(); ++j){
                a[s[j]-'a']++;
            }

            string key = to_string(a[0]);
            for(int k=0; k<a.size(); ++k){
                key+= ',' + to_string(a[k]);
            }
            auto iterator = m.find(key);
            if(iterator == m.end()){
                m.insert({key, {strs[i]}});
            } else {
                m[key].push_back(strs[i]);
            }
        }

        vector<vector<string>> ans;

        for(auto it:m){
            ans.push_back(it.second);
        }

        return ans;
    }// tc = n*m, sc = n*m
};
