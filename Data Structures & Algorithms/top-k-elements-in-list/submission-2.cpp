class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto it:nums) m[it]++;

        vector<vector<int>> v(nums.size()+1);

        for(auto it:m){
            v[it.second].push_back(it.first);
        }

        vector<int> ans;

        for(int i=v.size()-1; i>=0; i--){
            for(int j=0; j<v[i].size(); ++j){
                ans.push_back(v[i][j]);
                if(ans.size()==k) return ans;
            }
        }

        return ans;
    }
};
