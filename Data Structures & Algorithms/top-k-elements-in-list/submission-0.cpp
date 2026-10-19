class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(auto it:nums){
            m[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> sortedVal;

        for(auto it:m){
            sortedVal.push({it.second, it.first});
            if(sortedVal.size() > k){
                sortedVal.pop();
            }
        }

        vector<int> ans;

        while(!sortedVal.empty()){
            auto it = sortedVal.top();
            sortedVal.pop();
            ans.push_back(it.second);
        }

        return ans;
    }
};
